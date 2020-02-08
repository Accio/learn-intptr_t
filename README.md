A minimal example to summarize atol, (long), and (intptr_p)
===
Jitao David Zhang

# Background

During the process of submitting the ribiosUtils R package to CRAN, I met the problem that `(long)(char*)`, in which `(char*)` was returned by `va_arg(args, char *)`, causes warning message `cast from pointer to integer of different size`.

I first thought of using `atol`, but very soon realised that it was not the correct solution, because `char*` is just the wrong type. Using casting with `(long)` was fine for Unix and Mac, but not Windows.

It turned out that `(intptr_p)` solved the problem.

See the example file for details.
