# Batch-Dlls

## Injectoin
just use mdev-new inject.exe wich you can download source [here](https://github.com/mdev-new/batch_native/blob/master/src/hook.c)

Usage: `inject.exe filename.dll`
exsample: `inject.exe math.dll`

## Math.dll

### Cos, Sin ands Tan
Just set the input variable `cosI`/`sinI`/`tanI` to desired Value and get Value by reading the varable `cosO`/`sinO`/`tanO`

### Powers
Set the Value `powB` for basis and `powE` for exponent and get result variable from `powO`
exsample: powB = 5, powE = 3 is just 5³ so the variable `powO` is 125

### Squareroot
Set the value of the variable `sqrtI` and get the result via variable `sqrtO`