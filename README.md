# win-startup-headers
alternative crt startup headers for size-sensitive executable built by mingw

## Usage
### Console Applications
Console Applications use `main` entry point for ansi and `wmain` entry point for unicode.

Include `main.h` for `int main(argc,argv)` or include `mainv.h` for `int main()`,
and append `-nostartfiles` to your compiler parameters.

### Windows Applications
Windows Applications use `WinMain` entry point for ansi and `wWinMain` entry point for unicode.

Include `winmain.h` and append `-nostartfiles -mwindows` to your compiler parameters.

### Note
`commandlinetoargva.h` is **NOT** required for a unicode compilation.

## License
* `LGPL 2.1+` for `commandlinetoargva.h` and `examples/hello_win.c`
* `MIT` or `LGPL 2.1+` for anything else in this repo

## Examples
Check `examples` folder for examples.

## Credits
* https://github.com/myfreeer/mastervol
* https://stackoverflow.com/a/48301499/6848772
* https://github.com/pts/pts-tinype
* https://gist.github.com/pts/9ef2b1036d0b42508327559eeb2e0eb5
* https://www.winehq.org/
* https://github.com/futurist/CommandLineToArgvA
* http://repo.or.cz/tinycc.git