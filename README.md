# Batch-Dlls

## Injectoin
just use rundll32.

Usage: `rundll32 filename.dll,inject`
exsample: `rundll32 math.dll,inject`

You first need to inject evry dll you want to use.

## Math.dll

### Cos, Sin ands Tan
Just set the input variable `cosI`/`sinI`/`tanI` to desired Value and get Value by reading the varable `cosO`/`sinO`/`tanO`
Nomaly rounds Value, but with multipyer can be multipled, multiplyer var : `cosM`/`sinM`/`tanM`

### Powers
Set the Value `powB` for basis and `powE` for exponent and get result variable from `powO`
exsample: powB = 5, powE = 3 is just 5³ so the variable `powO` is 125

### Squareroot
Set the value of the variable `sqrtI` and get the result via variable `sqrtO`

## messageBox.dll
### Creating message box
To Set the Title of the Message box set the variabel `messageBox_title` to the desired title.
To Set the Text of the Message box set the variabel `messageBox_text` to the desired text.

To set set wich butten are available set `messageBox_button_type` to `messageBox_button_ok` wich makes an "Ok" button, `messageBox_button_yesno` wich displays a "yes" and "no",
`messageBox_button_okcancel` wich display a "yes" and "cancel" option or `messageBox_button_retrycancel` wich displays a "retry" and "cancel" option.

To set the Icon you can set `messageBox_icon_type` to `messageBox_icon_error` wich displays a red circel with a white "X" indicationg an error, `messageBox_icon_warning` wich displays a yellow triangle with block outline and exclamationmark that indecates a warning, `messageBox_icon_info` wich displays a blue circel with a white "i" indicating an information or `messageBox_icon_question` wich displays a blue corcel with an questionmark indecating a question.

After each change I do highly recomend setting `messageBox_clear_config` to not "0" to clear the internal config to reset the internel config from set variabels wich also clears return value and it will clear itself to zero.

Now to display the configured Messgae box set `messageBox_do_display` to not "0", it will reset itslef to "0".
Now you can use the variabel `messageBox_return` to get the clicked button.

OK = 1
Closing (Hitting x in top right cornder) = 1 
CANCEL = 2
RETRY = 4
YES = 6
NO = 7