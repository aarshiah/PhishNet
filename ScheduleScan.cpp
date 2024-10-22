#include <windows.h>
#include "UIElements.h"
#include "Resource.h"
#include <wingdi.h>
#include "framework.h"



extern bool schedulePageVisible = false;
HWND hStaticText;

void SetUpSchedulePage(HWND hWnd, HINSTANCE hInst) {
	DestroyHomePage(hWnd);
	CreateWindow(L"STATIC", L"Select which type of scan to run and how often you would like the scan to occur", WS_VISIBLE | WS_CHILD | SS_CENTER,
		100, 160, 250, 50, hWnd, NULL, hInst, NULL);

	CreateWindow(L"BUTTON", L"HOME", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW,
		600, 25, 50, 50, hWnd, (HMENU)ID_HOME_BUTTON, hInst, NULL);

}