#include <windows.h>
#include "UIElements.h"
#include "Resource.h"
#include <wingdi.h>
#include "framework.h"
#include <string>
#include <vector>


// Font global variables
HFONT hTitleFont = NULL;
HFONT hDescriptionFont = NULL;
HFONT hButtonFont = NULL;

// Global Variables:
HINSTANCE hInst;
WCHAR szTitle[MAX_LOADSTRING];
WCHAR szWindowClass[MAX_LOADSTRING];

// Hover states
bool isButton1Hovered = false;
bool isButton2Hovered = false;
bool isButton3Hovered = false;
bool isButton4Hovered = false;
bool isButton5Hovered = false;

// Page visibility bool
bool scanPageVisible = false;
bool CustomScanVisible = false; 

// Scan label definitions
HWND hQuickScanLabel, hSystemScanLabel, hCustomScanLabel, hStartScanButtonLabel;
HWND hScanLabel, hScheduleLabel, hHistoryLabel, hQuarantinedFilesLabel, hLastScanLabel;
HWND hScanTitle = NULL, hSystemScanTitle = NULL, hCustomScanTitle = NULL;
HWND hScanDescription = NULL, hSystemScanDescription = NULL, hCustomScanDescription = NULL;



void DisplayScanDetails(HWND hWnd, LPCWSTR scanTitle, LPCWSTR scanDescription) {
    // Clear the current content of the right panel if necessary
    // Then create new STATIC controls or update existing ones with the new scan details

    // For example, creating a STATIC text control for the title
    CreateWindow(L"STATIC", scanTitle, WS_VISIBLE | WS_CHILD | SS_CENTER,
        300, 100, 250, 40, hWnd, (HMENU)IDC_STATIC_SCAN_TITLE, hInst, NULL);
    SendMessage(hScanTitle, WM_SETFONT, (WPARAM)hTitleFont, TRUE);

    // Create new STATIC control for the description
    CreateWindow(L"STATIC", scanDescription, WS_VISIBLE | WS_CHILD | SS_LEFT,
        300, 150, 350, 100, hWnd, NULL, hInst, NULL);
    SendMessage(hScanDescription, WM_SETFONT, (WPARAM)hDescriptionFont, TRUE);
}

void LoadScanPage(HWND hWnd, HINSTANCE hInst) {
    // Create labels and buttons for scan page
    CreateWindow(L"STATIC", L"Scan Type Selection", WS_VISIBLE | WS_CHILD | SS_CENTER,
        50, 50, 600, 30, hWnd, NULL, hInst, NULL);
    CreateWindow(L"BUTTON", L"Quick Scan", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW,
        13, 175, 200, 75, hWnd, (HMENU)ID_QUICKSCAN_BUTTON, hInst, NULL);
    CreateWindow(L"BUTTON", L"System Scan", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW,
        13, 275, 200, 75, hWnd, (HMENU)ID_SYSTEMSCAN_BUTTON, hInst, NULL);
    CreateWindow(L"BUTTON", L"Custom Scan", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW,
        13, 375, 200, 75, hWnd, (HMENU)ID_CUSTOMSCAN_BUTTON, hInst, NULL);
    CreateWindow(L"BUTTON", L"Start Scan", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW,
        350, 275, 200, 75, hWnd, (HMENU)ID_STARTSCAN_BUTTON, hInst, NULL);
    CreateWindow(L"BUTTON", L"HOME", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW,
        85, 500, 50, 50, hWnd, (HMENU)ID_HOME_BUTTON, hInst, NULL);

    // Labels for scan type selection buttons
    hQuickScanLabel = CreateWindow(L"STATIC", L"Quick Scan", WS_VISIBLE | WS_CHILD | SS_CENTER,
        65, 200, 100, 25, hWnd, NULL, hInst, NULL);
    hSystemScanLabel = CreateWindow(L"STATIC", L"System Scan", WS_VISIBLE | WS_CHILD | SS_CENTER,
        65, 300, 100, 25, hWnd, NULL, hInst, NULL);
    hCustomScanLabel = CreateWindow(L"STATIC", L"Custom Scan", WS_VISIBLE | WS_CHILD | SS_CENTER,
        65, 400, 100, 25, hWnd, NULL, hInst, NULL);

    scanPageVisible = true; 

    InvalidateRect(hWnd, NULL, TRUE);  // Force redraw
}

void CustomScanPage(HWND hWnd, HINSTANCE hInst) {
    CustomScanVisible = true;
    CreateWindow(L"BUTTON", L"Browse & Select Files", WS_VISIBLE | WS_CHILD | SS_CENTER,
        400, 400, 200, 75, hWnd, (HMENU)ID_BUTTON_SELECT_FILE, hInst, NULL);

    InvalidateRect(hWnd, NULL, TRUE);

}


void DestroyScanPage(HWND hWnd) {

    if (hScanTitle) {
        DestroyWindow(hScanTitle);
        hScanTitle = NULL;  // Set to NULL after destroying
    }

    if (hScanDescription) {
        DestroyWindow(hScanDescription);
        hScanDescription = NULL;  // Set to NULL after destroying
    }

    // Destroy scan page controls
    DestroyWindow(GetDlgItem(hWnd, ID_QUICKSCAN_BUTTON));
    DestroyWindow(GetDlgItem(hWnd, ID_SYSTEMSCAN_BUTTON));
    DestroyWindow(GetDlgItem(hWnd, ID_CUSTOMSCAN_BUTTON));
    DestroyWindow(GetDlgItem(hWnd, ID_STARTSCAN_BUTTON));
    DestroyWindow(GetDlgItem(hWnd, ID_HOME_BUTTON));
    DestroyWindow(hQuickScanLabel);
    DestroyWindow(hSystemScanLabel);
    DestroyWindow(hCustomScanLabel);
    InvalidateRect(hWnd, NULL, TRUE);  // Force redraw

}

void SwitchScan(HWND hWnd) {
    if (hScanTitle) {
        DestroyWindow(hScanTitle);
        hScanTitle = NULL;  // Set to NULL after destroying
    }

    if (hScanDescription) {
        DestroyWindow(hScanDescription);
        hScanDescription = NULL;  // Set to NULL after destroying
    }
}

void SelectAndDisplayFiles(HWND hWnd) {
    OPENFILENAME ofn;
    wchar_t fileNames[1024] = { 0 };

    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = hWnd;
    ofn.lpstrFile = fileNames;
    ofn.nMaxFile = sizeof(fileNames);
    ofn.lpstrFilter = L"All Files\0*.*\0Test Files\0*.TXT\0";
    ofn.nFilterIndex = 1;
    ofn.Flags = OFN_EXPLORER | OFN_ALLOWMULTISELECT | OFN_FILEMUSTEXIST;

    if (GetOpenFileName(&ofn) == TRUE) {
        std::wstring filePath = ofn.lpstrFile;
        size_t offset = filePath.size() + 1;

        if (fileNames[offset] != L'\0') {
            std::wstring folderPath = filePath + L"\\";
            for (wchar_t* p = &fileNames[offset]; *p; p += wcslen(p) + 1) {
                std::wstring fileName = p;
                std::wstring fullPath = folderPath + fileName;

                MessageBox(hWnd, fullPath.c_str(), L"Selected Files", MB_OK);

            }
            
        }
        else {
            MessageBox(hWnd, filePath.c_str(), L"Selected File", MB_OK);
        }

    }
}

// Function to destroy controls before switching pages
void DestroyControls(HWND hWnd) {
    EnumChildWindows(hWnd, [](HWND hwnd, LPARAM lParam) -> BOOL {
        DestroyWindow(hwnd);
        return TRUE;
        }, 0);
}


