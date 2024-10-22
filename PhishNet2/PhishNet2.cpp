// PhishNet2.cpp : Defines the entry point for the application.
// 

#include "framework.h"
#include "UIElements.h"
#include "Resource.h"
#include "Resource.h"
#include <wingdi.h>

#define MAX_LOADSTRING 100




void DestroyStaticText(HWND hWnd) {
    if (hStaticText) {
        DestroyWindow(hStaticText);
        hStaticText = NULL;  // Set to NULL after destroying
    }
}

void CreateFonts() {
    // Create a font for titles
    hTitleFont = CreateFont(
        35,                    // Height
        0,                     // Width
        0,                     // Escapement
        0,                     // Orientation
        FW_BOLD,              // Weight
        FALSE,                // Italic
        FALSE,                // Underline
        FALSE,                // StrikeOut
        DEFAULT_CHARSET,      // Character set
        OUT_DEFAULT_PRECIS,   // Output precision
        CLIP_DEFAULT_PRECIS,  // Clipping precision
        DEFAULT_QUALITY,      // Quality
        DEFAULT_QUALITY,      // Output quality
        L"Arial"              // Font name
    );

    hDescriptionFont = CreateFont(
        24,                    // Height
        0,                     // Width
        0,                     // Escapement
        0,                     // Orientation
        FW_BOLD,              // Weight
        FALSE,                // Italic
        FALSE,                // Underline
        FALSE,                // StrikeOut
        DEFAULT_CHARSET,      // Character set
        OUT_DEFAULT_PRECIS,   // Output precision
        CLIP_DEFAULT_PRECIS,  // Clipping precision
        DEFAULT_QUALITY,      // Quality
        DEFAULT_QUALITY,      // Output quality
        L"Arial"              // Font name
    );

    hButtonFont = CreateFont(
        24,                    // Height
        0,                     // Width
        0,                     // Escapement
        0,                     // Orientation
        FW_BOLD,              // Weight
        FALSE,                // Italic
        FALSE,                // Underline
        FALSE,                // StrikeOut
        DEFAULT_CHARSET,      // Character set
        OUT_DEFAULT_PRECIS,   // Output precision
        CLIP_DEFAULT_PRECIS,  // Clipping precision
        DEFAULT_QUALITY,      // Quality
        DEFAULT_QUALITY,      // Output quality
        L"Arial"              // Font name
    );

}
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

    // Window dimensions
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

// Processes messages for the main window.
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {

    case WM_CREATE: {
        LoadHomePage(hWnd,hInst);
        CreateFonts();
        break;
    }

    case WM_CTLCOLORSTATIC:
    {
        HDC hdcStatic = (HDC)wParam;
        SetBkMode(hdcStatic, TRANSPARENT); // Set the background to transparent

        // Get the control ID to customize colors if needed
        HWND hControl = (HWND)lParam;
        int controlId = GetDlgCtrlID(hControl);

        return (LONG_PTR)NULL; // No brush
    }

    case WM_COMMAND: {
        // Handle button clicks
        switch (LOWORD(wParam)) {

        case ID_BUTTON1:
            DestroyHomePage(hWnd);  // Destroy home page controls
            SwitchScan(hWnd);
            LoadScanPage(hWnd, hInst);  // Load scan page controls
            DisplayScanDetails(hWnd, L"Quick Scan", L"A quick scan will go thorugh all the most important files on your device");
            InvalidateRect(hWnd, NULL, TRUE);  // Force redraw
            scanPageVisible = true;
            CustomScanVisible = false;

            break;

        case ID_BUTTON2:
            // Logic for Button 2
            schedulePageVisible = true;
            SetUpSchedulePage(hWnd, hInst);
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
            SwitchScan(hWnd);
            ShowWindow(hQuickScanLabel, SW_SHOW);
            InvalidateRect(hWnd, NULL, TRUE);  // Force redraw
            DisplayScanDetails(hWnd, L"Quick Scan", L"A quick scan will go thorugh all the most important files on your device");
            scanPageVisible = true;
            CustomScanVisible = false;
            break;

        case ID_SYSTEMSCAN_BUTTON:
            // Logic for System Scan button
            SwitchScan(hWnd);
            ShowWindow(hSystemScanLabel, SW_SHOW);
            InvalidateRect(hWnd, NULL, TRUE);  // Force redraw
            DisplayScanDetails(hWnd, L"System Scan", L"A complete scan of all system disks & directories");
            scanPageVisible = true;
            CustomScanVisible = false;
            break;

        case ID_CUSTOMSCAN_BUTTON:
            SwitchScan(hWnd);
            ShowWindow(hCustomScanLabel, SW_SHOW);
            DisplayScanDetails(hWnd, L"Custom Scan", L"Select Drive(s), Directories, or Files to scan");
            InvalidateRect(hWnd, NULL, TRUE);  // Force redraw
            scanPageVisible = false;
            CustomScanVisible = true;
            break;

        case ID_STARTSCAN_BUTTON:
            // Logic for Start Scan button
            ShowWindow(hStartScanButtonLabel, SW_SHOW);
            InvalidateRect(hWnd, NULL, TRUE);  // Force redraw
            MessageBox(hWnd, L"Starting scan...", L"Scan", MB_OK);

            scanPageVisible = true;

            break;

        case ID_HOME_BUTTON:
            // Logic for Home Button
            DestroyScanPage(hWnd);  // Destroy scan page controls
            DestroyControls(hWnd);
            LoadHomePage(hWnd, hInst);  // Load home page controls
            InvalidateRect(hWnd, NULL, TRUE);  // Force redraw
            homePageVisible = true;
            CustomScanVisible = false;
            scanPageVisible = false;
            schedulePageVisible = false;

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

        // Draw gray bar at the top of the window
        RECT rect;
        rect.left = 0;
        rect.top = 0;
        rect.right = 700; // Change to match window width
        rect.bottom = 100; // Set the height of the bar

        // Gray Brush 
        HBRUSH hGrayBrush = CreateSolidBrush(RGB(169, 169, 169)); // Light gray
        FillRect(hdc, &rect, hGrayBrush);
        DeleteObject(hGrayBrush); // Clean up the brush

        if (homePageVisible){
            // Draw the gray bar at the bottom of the window (home page, settings page)
            RECT bottomRect;
            bottomRect.left = 0;
            bottomRect.top = 600; // Starting y position for the bottom bar
            bottomRect.right = 700; // Change to match window width
            bottomRect.bottom = 700; // Set the height of the bar (bottom of the window)

            // New gray brush for the bottom bar
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

        if (schedulePageVisible) {
            // Draw the gray bar at the bottom of the window (home page, settings page)
            RECT bottomRect;
            bottomRect.left = 0;
            bottomRect.top = 600; // Starting y position for the bottom bar
            bottomRect.right = 700; // Change to match window width
            bottomRect.bottom = 700; // Set the height of the bar (bottom of the window)

            // New gray brush for the bottom bar
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

            RECT middleRect;
            middleRect.left = 50;
            middleRect.top = 125;
            middleRect.right = 400;
            middleRect.bottom = 250;

            HBRUSH hBlackBrush = CreateSolidBrush(RGB(0, 0, 0));
            FillRect(hdc, &middleRect, hBlackBrush);
            DeleteObject(hBlackBrush);

            RECT middleTitleRect;
            middleTitleRect.left = 60;
            middleTitleRect.top = 135;
            middleTitleRect.right = 390;
            middleTitleRect.bottom = 240;

            HBRUSH hDarkGrayBrush = CreateSolidBrush(RGB(77, 77, 77));
            FillRect(hdc, &middleTitleRect, hDarkGrayBrush);
            DeleteObject(hDarkGrayBrush);
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
            DeleteObject(hGrayBrush); 

            RECT LeftRect;
            LeftRect.left = 0;
            LeftRect.top = 100; 
            LeftRect.right = 226; 
            LeftRect.bottom = 700; 

            // Create a new brush for the bottom bar
            hGrayBrush = CreateSolidBrush(RGB(169, 169, 169)); 
            FillRect(hdc, &LeftRect, hGrayBrush);
            DeleteObject(hGrayBrush);

            // Draw the vertical black divider
            HPEN hOldPen = (HPEN)SelectObject(hdc, CreatePen(PS_SOLID, 3, RGB(0, 0, 0))); // Black color
            MoveToEx(hdc, 226, 100, NULL); // Start point of the vertical line (x=226, y=0)
            LineTo(hdc, 226, clientRect.bottom); // End point of the vertical line (x=226, y=clientRect.bottom)

            // Draw the horizontal black line divider
            MoveToEx(hdc, 226, 360, NULL); // Start point of the horizontal line
            LineTo(hdc, 700, 360); // End point 

            // Draw the horizontal black line divider
            MoveToEx(hdc, 0, 100, NULL); // Start point of the horizontal line
            LineTo(hdc, 700, 100); // End point

            SelectObject(hdc, hOldPen); // Restore the old pen
            DeleteObject(SelectObject(hdc, CreatePen(PS_NULL, 0, 0))); // Clean up the created pen
        }

        if (CustomScanVisible){
            RECT CustomRightRect;
            CustomRightRect.left = 226;
            CustomRightRect.top = 100; // Starting y position for the bottom bar
            CustomRightRect.right = 700; // Change to match window width
            CustomRightRect.bottom = 700; // Set the height of the bar (bottom of the window)

            // Create a new brush for the right side
            HBRUSH hWhiteBrush = CreateSolidBrush(RGB(255, 255, 255)); // white
            FillRect(hdc, &CustomRightRect, hWhiteBrush);
            DeleteObject(hWhiteBrush);


            RECT LeftRect;
            LeftRect.left = 0;
            LeftRect.top = 100;
            LeftRect.right = 226;
            LeftRect.bottom = 700;

            // Create a new brush for the bottom bar
            hGrayBrush = CreateSolidBrush(RGB(169, 169, 169));
            FillRect(hdc, &LeftRect, hGrayBrush);
            DeleteObject(hGrayBrush);


            RECT YellowRect;
            YellowRect.left = 225;
            YellowRect.top = 200;
            YellowRect.right = 700;
            YellowRect.bottom = 600;

            HBRUSH hYellowBrush = CreateSolidBrush(RGB(252, 244, 204)); // yellow
            FillRect(hdc, &YellowRect, hYellowBrush);
            DeleteObject(hYellowBrush);


            // Draw the vertical black divider
            HPEN hOldPen = (HPEN)SelectObject(hdc, CreatePen(PS_SOLID, 3, RGB(0, 0, 0))); // Black color
            MoveToEx(hdc, 226, 100, NULL); // Start point of the vertical line (x=226, y=0)
            LineTo(hdc, 226, clientRect.bottom); // End point of the vertical line (x=226, y=clientRect.bottom)


            // Draw the horizontal black line divider
            MoveToEx(hdc, 0, 100, NULL); // Start point of the horizontal line
            LineTo(hdc, 700, 100); // End point

            // Draw the top border of the yellow rectangle
            MoveToEx(hdc, 226, 200, NULL); // Start point of the horizontal line
            LineTo(hdc, 700, 200); // End point

            // Draw the bottom border of the left rectangle
            MoveToEx(hdc, 226, 600, NULL); // Start point of the horizontal line
            LineTo(hdc, 700, 600); // End point

        }

        EndPaint(hWnd, &ps);
        return 0;
    }


    case WM_DESTROY: {

        DeleteObject(hTitleFont);
        DeleteObject(hDescriptionFont);
        DeleteObject(hButtonFont);

        PostQuitMessage(0);
        break;
    }

    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
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