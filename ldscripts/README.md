# ldscripts
This folder contains ld linker scripts from [mastervol](https://github.com/myfreeer/mastervol) project,
which would remove `.eh_frame` `.pdata` `.xdata` `.tls` `.rsrc` sections,
and merge `.rdata` section into `.data` section.

## Caution
Make sure to test your executable after using this linker scripts.

## Usage
Use compiler parameter `-Wl,-T,/path/to/file/xxx.ldscript` or linker parameter `-T /path/to/file/xxx.ldscript`.

Use `x86_64.ldscript` for 64-bit targets and `i386.ldscript` for 32-bit targets.
