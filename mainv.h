// Small alternative startfile for main()
// Build with gcc perms:
// -nostartfiles
#pragma once
#ifndef STARTFILE_MAIN_H
#define STARTFILE_MAIN_H
#include <windows.h>

#ifdef UNICODE
#define wmain() _wmain()
int wmain();
#else
// workaround undefined reference to `_pei386_runtime_relocator'
#define main() _main()
int main();
#endif
int __cdecl mainCRTStartup() {
#ifdef UNICODE
  const int exitCode = wmain();
#else
  const int exitCode = main();
#endif
  ExitProcess(exitCode);
  return exitCode;
}
#endif
