// UIElements.h
#ifndef UIELEMENTS_H
#define UIELEMENTS_H
#define MAX_LOADSTRING 100

#include <commdlg.h>
#include <windows.h>
#include "Resource.h"


// Font global variables
extern HFONT hTitleFont;
extern HFONT hDescriptionFont;
extern HFONT hButtonFont;
extern HWND hStaticText;

// Global Variables:
extern HINSTANCE hInst;  // current instance
extern WCHAR szTitle[MAX_LOADSTRING];  // The title bar text
extern WCHAR szWindowClass[MAX_LOADSTRING];  // The main window class name

// Hover states
extern bool isButton1Hovered;
extern bool isButton2Hovered;
extern bool isButton3Hovered;
extern bool isButton4Hovered;
extern bool isButton5Hovered;

// Page visibility bool
extern bool homePageVisible;
extern bool scanPageVisible;
extern bool schedulePageVisible;
extern bool CustomScanVisible;

// Scan label definitions
extern HWND hQuickScanLabel, hSystemScanLabel, hCustomScanLabel, hStartScanButtonLabel;
extern HWND hScanLabel, hScheduleLabel, hHistoryLabel, hQuarantinedFilesLabel, hLastScanLabel;
extern HWND hScanTitle, hSystemScanTitle, hCustomScanTitle;
extern HWND hScanDescription, hSystemScanDescription, hCustomScanDescription;

// Function prototypes
void CreateFonts();

// Home Page
void LoadHomePage(HWND hWnd, HINSTANCE hInst);
void DestroyHomePage(HWND hWnd);

// Scan Pages
void DisplayScanDetails(HWND hWnd, LPCWSTR scanTitle, LPCWSTR scanDescription);
void LoadScanPage(HWND hWnd, HINSTANCE hInst);
void DestroyScanPage(HWND hWnd);
void SwitchScan(HWND hWnd);
void DestroyControls(HWND hWnd);
void CustomScanPage(HWND hWnd, HINSTANCE hInst);

// Schedule Page
void SetUpSchedulePage(HWND hWnd, HINSTANCE hInst);

// Select files from Windows Explorer
void SelectAndDisplayFiles(HWND hWnd);


#endif // UIELEMENTS_H
