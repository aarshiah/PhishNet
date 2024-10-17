// PhishNet2.cpp : Defines the entry point for the application.
// 

#include "framework.h"
#include "PhishNet2.h"
#include "Resource.h"
#include <wingdi.h>

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // The main window class name
HFONT hButtonFont = NULL;

// Hover states
bool isButton1Hovered = false;
bool isButton2Hovered = false;
bool isButton3Hovered = false;
bool isButton4Hovered = false;
bool isButton5Hovered = false;

// Page visibility bool
bool scanPageVisible = false;

// Scan label definition
HWND hQuickScanLabel;
HWND hSystemScanLabel;
HWND hCustomScanLabel;
HWND hStartScanButtonLabel;


LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);



void FillSolidRect(HDC hdc, RECT* rect, COLORREF color) {
    HBRUSH hBrush = CreateSolidBrush(color);
    FillRect(hdc, rect, hBrush);
    DeleteObject(hBrush);
}

// Forward declarations of functions included in this code module:
ATOM MyRegisterClass(HINSTANCE hInstance);
BOOL InitInstance(HINSTANCE, int);
INT_PTR CALLBACK About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR lpCmdLine,
    _In_ int nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_PHISHNET, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance(hInstance, nCmdShow)) {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_PHISHNET));
    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0)) {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int)msg.wParam;
}

// Registers the window class.
ATOM MyRegisterClass(HINSTANCE hInstance) {
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;  // The WndProc function
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON2));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = CreateSolidBrush(RGB(255, 255, 255));
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

// Saves instance handle and creates the main window
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow) {
    hInst = hInstance; // Store instance handle in our global variable

    // Get the screen width and height
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);

    // Set the window dimensions
    int windowWidth = 700;
    int windowHeight = 700;

    // Calculate the center position
    int x = (screenWidth - windowWidth) / 2;
    int y = (screenHeight - windowHeight) / 2;

    // Create the window
    HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW | WS_VISIBLE,
        x, y, windowWidth, windowHeight, nullptr, nullptr, hInstance, nullptr);

    if (!hWnd) {
        MessageBox(nullptr, L"Failed to create window!", L"Error", MB_ICONERROR);
        return FALSE; // Return false if window creation fails
    }

    // Ensure the window is shown and updated
    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    return TRUE;
}

// Function to destroy controls before switching pages
void DestroyControls(HWND hWnd) {
    EnumChildWindows(hWnd, [](HWND hwnd, LPARAM lParam) -> BOOL {
        DestroyWindow(hwnd);
        return TRUE;
        }, 0);
}

// Global define of button labels
HWND hScanLabel, hScheduleLabel, hHistoryLabel, hQuarantinedFilesLabel, hLastScanLabel;


// Processes messages for the main window.
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
    case WM_CREATE: {

        hButtonFont = CreateFont(
            24,                  // Height
            0,                   // Width
            0,                   // Escapement
            0,                   // Orientation
            FW_NORMAL,          // Weight
            FALSE,              // Italic
            FALSE,              // Underline
            FALSE,              // StrikeOut
            DEFAULT_CHARSET,    // CharSet
            OUT_OUTLINE_PRECIS, // OutputPrecision
            CLIP_DEFAULT_PRECIS, // ClippingPrecision
            DEFAULT_QUALITY,     // Quality
            0,                   // Family
            L"Arial"            // Font name
        );

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
        SendMessage(hScanLabel, WM_SETFONT, (WPARAM)hButtonFont, TRUE); // Set font

        hScheduleLabel = CreateWindow(L"STATIC", L"SCHEDULE SCAN", WS_VISIBLE | WS_CHILD | SS_CENTER,
            265, 310, 150, 20, hWnd, NULL, hInst, NULL);
        SendMessage(hScheduleLabel, WM_SETFONT, (WPARAM)hButtonFont, TRUE); // Set font

        hHistoryLabel = CreateWindow(L"STATIC", L"HISTORY", WS_VISIBLE | WS_CHILD | SS_CENTER,
            475, 310, 150, 20, hWnd, NULL, hInst, NULL);
        SendMessage(hHistoryLabel, WM_SETFONT, (WPARAM)hButtonFont, TRUE); // Set font

        hQuarantinedFilesLabel = CreateWindow(L"STATIC", L"QUARANTINED FILES", WS_VISIBLE | WS_CHILD | SS_CENTER,
            75, 510, 250, 20, hWnd, NULL, hInst, NULL);
        SendMessage(hQuarantinedFilesLabel, WM_SETFONT, (WPARAM)hButtonFont, TRUE); // Set font

        hLastScanLabel = CreateWindow(L"STATIC", L"LAST SCAN", WS_VISIBLE | WS_CHILD | SS_CENTER,
            350, 510, 250, 20, hWnd, NULL, hInst, NULL);
        SendMessage(hLastScanLabel, WM_SETFONT, (WPARAM)hButtonFont, TRUE); // Set font

        break;
    }


    case WM_COMMAND: {
        // Handle button clicks
        switch (LOWORD(wParam)) {

        case ID_BUTTON1:
            // Destroy homepage buttons if needed
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

            scanPageVisible = true;  // Update flag
            InvalidateRect(hWnd, NULL, TRUE);


            // Create new controls for the new page
            CreateWindow(L"STATIC", L"Scan Type Selection", WS_VISIBLE | WS_CHILD | SS_CENTER,
                50, 50, 600, 30, hWnd, NULL, hInst, NULL);

            // Create buttons for selecting scan types
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

            
            break;

        case ID_BUTTON2:
            // Logic for Button 2
            MessageBox(hWnd, L"Button 2 clicked", L"Info", MB_OK);
            break;
        case ID_BUTTON3:
            // Logic for Button 3
            MessageBox(hWnd, L"Button 3 clicked", L"Info", MB_OK);
            break;
        case ID_BUTTON4:
            // Logic for Button 4
            MessageBox(hWnd, L"Button 4 clicked", L"Info", MB_OK);
            break;
        case ID_BUTTON5:
            // Logic for Button 5
            MessageBox(hWnd, L"Button 5 clicked", L"Info", MB_OK);
            break;
        case ID_QUICKSCAN_BUTTON:
            // Logic for Quick Scan button
            ShowWindow(hQuickScanLabel, SW_SHOW);
            InvalidateRect(hWnd, NULL, TRUE);  // Force redraw
            MessageBox(hWnd, L"Quick Scan clicked", L"Scan", MB_OK);
            break;
        case ID_SYSTEMSCAN_BUTTON:
            // Logic for System Scan button
            ShowWindow(hSystemScanLabel, SW_SHOW);
            InvalidateRect(hWnd, NULL, TRUE);  // Force redraw
            MessageBox(hWnd, L"System Scan clicked", L"Scan", MB_OK);
            break;
        case ID_CUSTOMSCAN_BUTTON:
            ShowWindow(hCustomScanLabel, SW_SHOW);
            InvalidateRect(hWnd, NULL, TRUE);  // Force redraw
            // Logic for Custom Scan button
            MessageBox(hWnd, L"Custom Scan clicked", L"Scan", MB_OK);
            break;
        case ID_STARTSCAN_BUTTON:
            // Logic for Start Scan button
            ShowWindow(hStartScanButtonLabel, SW_SHOW);
            InvalidateRect(hWnd, NULL, TRUE);  // Force redraw
            MessageBox(hWnd, L"Starting scan...", L"Scan", MB_OK);
            break;
        case ID_HOME_BUTTON:
            // Logic for Button 5
            MessageBox(hWnd, L"Going home... maybe", L"Info", MB_OK);
            break;
        }
        break;
    }

    case WM_MOUSEMOVE: {
        // Get the mouse position relative to the client area
        POINT pt = { LOWORD(lParam), HIWORD(lParam) };

        // Create a RECT for each button and get its screen position
        RECT button1Rect, button2Rect, button3Rect, button4Rect, button5Rect;
        GetWindowRect(GetDlgItem(hWnd, ID_BUTTON1), &button1Rect);
        GetWindowRect(GetDlgItem(hWnd, ID_BUTTON2), &button2Rect);
        GetWindowRect(GetDlgItem(hWnd, ID_BUTTON3), &button3Rect);
        GetWindowRect(GetDlgItem(hWnd, ID_BUTTON4), &button4Rect);
        GetWindowRect(GetDlgItem(hWnd, ID_BUTTON5), &button5Rect);

        // Convert button screen coordinates to client coordinates
        MapWindowPoints(NULL, hWnd, (LPPOINT)&button1Rect, 2);
        MapWindowPoints(NULL, hWnd, (LPPOINT)&button2Rect, 2);
        MapWindowPoints(NULL, hWnd, (LPPOINT)&button3Rect, 2);
        MapWindowPoints(NULL, hWnd, (LPPOINT)&button4Rect, 2);
        MapWindowPoints(NULL, hWnd, (LPPOINT)&button5Rect, 2);

        // Check hover state and invalidate for each button
        bool button1NewState = PtInRect(&button1Rect, pt);
        bool button2NewState = PtInRect(&button2Rect, pt);
        bool button3NewState = PtInRect(&button3Rect, pt);
        bool button4NewState = PtInRect(&button4Rect, pt);
        bool button5NewState = PtInRect(&button5Rect, pt);

        if (isButton1Hovered != button1NewState) {
            isButton1Hovered = button1NewState;
            InvalidateRect(GetDlgItem(hWnd, ID_BUTTON1), NULL, TRUE);
        }
        if (isButton2Hovered != button2NewState) {
            isButton2Hovered = button2NewState;
            InvalidateRect(GetDlgItem(hWnd, ID_BUTTON2), NULL, TRUE);
        }
        if (isButton3Hovered != button3NewState) {
            isButton3Hovered = button3NewState;
            InvalidateRect(GetDlgItem(hWnd, ID_BUTTON3), NULL, TRUE);
        }
        if (isButton4Hovered != button4NewState) {
            isButton4Hovered = button4NewState;
            InvalidateRect(GetDlgItem(hWnd, ID_BUTTON4), NULL, TRUE);
        }
        if (isButton5Hovered != button5NewState) {
            isButton5Hovered = button5NewState;
            InvalidateRect(GetDlgItem(hWnd, ID_BUTTON5), NULL, TRUE);
        }


        break;
    }

    case WM_DRAWITEM: {
        LPDRAWITEMSTRUCT lpDIS = (LPDRAWITEMSTRUCT)lParam;
        if (lpDIS->CtlType == ODT_BUTTON) {
            HDC hdc = lpDIS->hDC;
            RECT rc = lpDIS->rcItem;

            // Set color based on hover state (same as before)
            COLORREF fillColor = RGB(240, 240, 240);
            if (lpDIS->itemState & ODS_SELECTED) {
                fillColor = RGB(200, 200, 200);
            }
            else if (isButton1Hovered && lpDIS->itemID == ID_BUTTON1) {
                fillColor = RGB(200, 255, 200);
            }

            // Draw the filled rounded rectangle
            int radius = 20; // Corner radius
            HBRUSH hBrush = CreateSolidBrush(fillColor);
            SelectObject(hdc, hBrush);
            RoundRect(hdc, rc.left, rc.top, rc.right, rc.bottom, radius, radius);
            DeleteObject(hBrush);

            // Draw the border
            SelectObject(hdc, GetStockObject(BLACK_PEN));
            RoundRect(hdc, rc.left, rc.top, rc.right, rc.bottom, radius, radius);

            // Load and draw the icon for Button1
            if (lpDIS->itemID == ID_BUTTON1) {
                // Load the icon
                HICON hIcon = (HICON)LoadImage(hInst, MAKEINTRESOURCE(IDI_ICON3), IMAGE_ICON, 0, 0, LR_DEFAULTCOLOR);
                if (hIcon) {
                    // Center icon position
                    int iconWidth = 96;  // Adjust based on your icon size
                    int iconHeight = 96;
                    int x = (rc.right - rc.left - iconWidth) / 2;
                    int y = (rc.bottom - rc.top - iconHeight) / 2;

                    // Draw the icon
                    DrawIconEx(hdc, rc.left + x, rc.top + y, hIcon, iconWidth, iconHeight, 0, NULL, DI_NORMAL);

                    // Clean up the icon handle
                    DestroyIcon(hIcon);
                }
                else {
                    MessageBox(NULL, L"Failed to load icon!", L"Error", MB_OK | MB_ICONERROR);
                }
            }

            // Draw button text
            SetBkMode(hdc, TRANSPARENT);
            SetTextColor(hdc, RGB(0, 0, 0));
            DrawText(hdc, L"", -1, &rc, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

            return TRUE;
        }
    }
    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);

        // Draw the gray bar at the top of the window
        RECT rect;
        rect.left = 0;
        rect.top = 0;
        rect.right = 700; // Change to match window width
        rect.bottom = 100; // Set the height of the bar

        // Create a brush with gray color
        HBRUSH hGrayBrush = CreateSolidBrush(RGB(169, 169, 169)); // Light gray
        FillRect(hdc, &rect, hGrayBrush);
        DeleteObject(hGrayBrush); // Clean up the brush

        if (!scanPageVisible) {
            // Draw the gray bar at the bottom of the window
            RECT bottomRect;
            bottomRect.left = 0;
            bottomRect.top = 600; // Starting y position for the bottom bar
            bottomRect.right = 700; // Change to match window width
            bottomRect.bottom = 700; // Set the height of the bar (bottom of the window)

            // Create a new brush for the bottom bar
            hGrayBrush = CreateSolidBrush(RGB(169, 169, 169)); // Light gray
            FillRect(hdc, &bottomRect, hGrayBrush);
            DeleteObject(hGrayBrush); // Clean up the brush

            // Draw borders around the client area
            HPEN hBorderPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0)); // Black color for the border
            HPEN hOldPen2 = (HPEN)SelectObject(hdc, hBorderPen);

            // Top border
            MoveToEx(hdc, 0, 100, NULL);
            LineTo(hdc, 700, 100);

            // Left border
            MoveToEx(hdc, 0, 100, NULL);
            LineTo(hdc, 0, 600);

            // Right border
            MoveToEx(hdc, 697, 100, NULL);
            LineTo(hdc, 697, 600);

            // Bottom border
            MoveToEx(hdc, 0, 600, NULL);
            LineTo(hdc, 700, 600);

            SelectObject(hdc, hOldPen2); // Restore the old pen
            DeleteObject(hBorderPen); // Clean up the border pen

        }

        // Get the height of the client area
        RECT clientRect;
        GetClientRect(hWnd, &clientRect);

        // Draw the Scan page elements
        if (scanPageVisible) {

            RECT RightRect;
            RightRect.left = 226;
            RightRect.top = 360; // Starting y position for the bottom bar
            RightRect.right = 700; // Change to match window width
            RightRect.bottom = 700; // Set the height of the bar (bottom of the window)

            // Create a new brush for the bottom bar
            hGrayBrush = CreateSolidBrush(RGB(169, 169, 169)); // Light gray
            FillRect(hdc, &RightRect, hGrayBrush);
            DeleteObject(hGrayBrush); // Clean up the brush

            RECT LeftRect;
            LeftRect.left = 0;
            LeftRect.top = 100; // Starting y position for the bottom bar
            LeftRect.right = 226; // Change to match window width
            LeftRect.bottom = 700; // Set the height of the bar (bottom of the window)

            // Create a new brush for the bottom bar
            hGrayBrush = CreateSolidBrush(RGB(169, 169, 169)); // Light gray
            FillRect(hdc, &LeftRect, hGrayBrush);
            DeleteObject(hGrayBrush); // Clean up the brush

            // Draw the vertical black divider
            HPEN hOldPen = (HPEN)SelectObject(hdc, CreatePen(PS_SOLID, 3, RGB(0, 0, 0))); // Black color
            MoveToEx(hdc, 226, 100, NULL); // Start point of the vertical line (x=226, y=0)
            LineTo(hdc, 226, clientRect.bottom); // End point of the vertical line (x=226, y=clientRect.bottom)

            // Draw the horizontal black line divider
            MoveToEx(hdc, 226, 360, NULL); // Start point of the horizontal line
            LineTo(hdc, 700, 360); // End point of the horizontal line

            // Draw the horizontal black line divider
            MoveToEx(hdc, 0, 100, NULL); // Start point of the horizontal line
            LineTo(hdc, 700, 100); // End point of the horizontal line

            SelectObject(hdc, hOldPen); // Restore the old pen
            DeleteObject(SelectObject(hdc, CreatePen(PS_NULL, 0, 0))); // Clean up the created pen
        }

        EndPaint(hWnd, &ps);
        return 0;
    }


    case WM_DESTROY: {
        PostQuitMessage(0);
        break;
    }

    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

void DisplayScanDetails(HWND hWnd, LPCWSTR scanTitle, LPCWSTR scanDescription) {
    // Clear the current content of the right panel if necessary
    // Then create new STATIC controls or update existing ones with the new scan details

    // For example, creating a STATIC text control for the title
    CreateWindow(L"STATIC", scanTitle, WS_VISIBLE | WS_CHILD | SS_CENTER,
        300, 100, 250, 20, hWnd, NULL, hInst, NULL);

    // And another STATIC control for the description
    CreateWindow(L"STATIC", scanDescription, WS_VISIBLE | WS_CHILD | SS_LEFT,
        300, 130, 350, 100, hWnd, NULL, hInst, NULL);
}

INT_PTR CALLBACK NewPageProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL) {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

// About dialog procedure
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL) {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
