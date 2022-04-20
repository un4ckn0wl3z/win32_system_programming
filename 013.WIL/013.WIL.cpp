#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <wil\resource.h>


void DoWork();

struct Handle {
	explicit Handle(HANDLE h = nullptr) : _h(h) {}
	~Handle() { Close(); }
	// delete copy-ctor and copy-assignment
	Handle(const Handle&) = delete;
	Handle& operator=(const Handle&) = delete;
	// allow move (transfer ownership)
	Handle(Handle&& other) : _h(other._h) {
		other._h = nullptr;
	}
	Handle& operator=(Handle&& other) {
		if (this != &other) {
			Close();
			_h = other._h;
			other._h = nullptr;
		}
		return *this;
	}
	operator bool() const {
		return _h != nullptr && _h != INVALID_HANDLE_VALUE;
	}
	HANDLE Get() const {
		printf("Handle Get\n");
		return _h;
	}
	void Close() {
		if (_h) {
			printf("Handle closed\n");
			::CloseHandle(_h);
			_h = nullptr;
		}
	}
private:
	HANDLE _h;
};




int main()
{
	Handle hMyEvent(::CreateEvent(nullptr, TRUE, FALSE, nullptr));

	if (!hMyEvent) {
		// handle failure
		return 1;
	}

	::SetEvent(hMyEvent.Get());

	Handle hOtherEvent(std::move(hMyEvent));
	::ResetEvent(hOtherEvent.Get());

	DoWork();


	return 0;
}


void DoWork() {
	wil::unique_handle hMyEvent(::CreateEvent(nullptr, TRUE, FALSE, nullptr));
	if (!hMyEvent) {
		// handle failure
		return;
	}
	::SetEvent(hMyEvent.get());
	// move ownership
	auto hOtherEvent(std::move(hMyEvent));
	::ResetEvent(hOtherEvent.get());
}






