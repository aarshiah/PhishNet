#include <windows.h>
#include "UIElements.h"
#include "Resource.h"
#include <wingdi.h>
#include "framework.h"


extern bool homePageVisible = true;

void LoadHomePage(HWND hWnd, HINSTANCE hInst) {
    // Create buttons for home page
    CreateWindow(L"BUTTON", L"Button 1", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_OWNERDRAW,
        50, 150, 150, 150, hWnd, (HMENU)ID_BUTTON1, hInst, NULL);
    CreateWindow(L"BUTTON", L"Button 2", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_OWNERDRAW,
        265, 150, 150, 150, hWnd, (HMENU)ID_BUTTON2, hInst, NULL);
    CreateWindow(L"BUTTON", L"Button 3", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_OWNERDRAW,
        475, 150, 150, 150, hWnd, (HMENU)ID_BUTTON3, hInst, NULL);
    CreateWindow(L"BUTTON", L"Button 4", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_OWNERDRAW,
        75, 350, 250, 150, hWnd, (HMENU)ID_BUTTON4, hInst, NULL);
    CreateWindow(L"BUTTON", L"Button 5", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_OWNERDRAW,
        350, 350, 250, 150, hWnd, (HMENU)ID_BUTTON5, hInst, NULL);

    // Create Button Labels
    hScanLabel = CreateWindow(L"STATIC", L"SCAN", WS_VISIBLE | WS_CHILD | SS_CENTER,
        50, 310, 150, 20, hWnd, NULL, hInst, NULL);
    hScheduleLabel = CreateWindow(L"STATIC", L"SCHEDULE SCAN", WS_VISIBLE | WS_CHILD | SS_CENTER,
        265, 310, 150, 20, hWnd, NULL, hInst, NULL);
    hHistoryLabel = CreateWindow(L"STATIC", L"HISTORY", WS_VISIBLE | WS_CHILD | SS_CENTER,
        475, 310, 150, 20, hWnd, NULL, hInst, NULL);
    hQuarantinedFilesLabel = CreateWindow(L"STATIC", L"QUARANTINED FILES", WS_VISIBLE | WS_CHILD | SS_CENTER,
        75, 510, 250, 20, hWnd, NULL, hInst, NULL);
    hLastScanLabel = CreateWindow(L"STATIC", L"LAST SCAN", WS_VISIBLE | WS_CHILD | SS_CENTER,
        350, 510, 250, 20, hWnd, NULL, hInst, NULL);
}

void DestroyHomePage(HWND hWnd) {
    // Destroy home page buttons and labels
    DestroyWindow(GetDlgItem(hWnd, ID_BUTTON1));
    DestroyWindow(GetDlgItem(hWnd, ID_BUTTON2));
    DestroyWindow(GetDlgItem(hWnd, ID_BUTTON3));
    DestroyWindow(GetDlgItem(hWnd, ID_BUTTON4));
    DestroyWindow(GetDlgItem(hWnd, ID_BUTTON5));
    DestroyWindow(hScanLabel);
    DestroyWindow(hScheduleLabel);
    DestroyWindow(hHistoryLabel);
    DestroyWindow(hQuarantinedFilesLabel);
    DestroyWindow(hLastScanLabel);
    InvalidateRect(hWnd, NULL, TRUE);  // Force redraw
}