// Small alternative startfile for WinMain()
// Build with gcc perms:
// -nostartfiles -mwindows
#pragma once
#ifndef STARTFILE_WINMAIN_H
#define STARTFILE_WINMAIN_H
#define MAX_COMMAND_LINE_LENGTH 32768
#include <windows.h>

#ifdef UNICODE
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PWSTR lpCmdLine, int nCmdShow);
#else
#include "commandlinetoargva.h"
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int nCmdShow);
#endif
int __cdecl WinMainCRTStartup() {
  int __arg_c;
#ifdef UNICODE
  wchar_t **__arg_v = CommandLineToArgvW(GetCommandLineW(), &__arg_c);
  wchar_t __lpCmdLine[MAX_COMMAND_LINE_LENGTH + 1];
  ZeroMemory(__lpCmdLine, sizeof(__lpCmdLine));
  for (int i = 1; i < __arg_c; i++) {
    wcscat(__lpCmdLine, __arg_v[i]);
    wcscat(__lpCmdLine, L" ");
  }
#else
  char **__arg_v = CommandLineToArgvA(GetCommandLineA(), &__arg_c);
  char __lpCmdLine[MAX_COMMAND_LINE_LENGTH + 1];
  ZeroMemory(__lpCmdLine, sizeof(__lpCmdLine));
  for (int i = 1; i < __arg_c; i++) {
    strcat(__lpCmdLine, __arg_v[i]);
    strcat(__lpCmdLine, " ");
  }
#endif
  LocalFree(__arg_v);
  STARTUPINFO startupInfo;
  ZeroMemory(&startupInfo, sizeof(STARTUPINFO));
  GetStartupInfo(&startupInfo);
  DWORD __nShowCmd = SW_SHOWDEFAULT;
  __nShowCmd = startupInfo.dwFlags & STARTF_USESHOWWINDOW
                 ? startupInfo.wShowWindow
                 : SW_SHOWDEFAULT;
  const int exitCode =
#ifdef UNICODE
      wWinMain(GetModuleHandleW(NULL), NULL, __lpCmdLine, __nShowCmd);
#else
      WinMain(GetModuleHandleA(NULL), NULL, __lpCmdLine, __nShowCmd);
#endif
  ExitProcess(exitCode);
  return exitCode;
}
#endif
