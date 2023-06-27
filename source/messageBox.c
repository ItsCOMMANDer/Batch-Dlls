#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdlib.h>
#include "Injector.h"

char input_messageBox_text[4096];
char input_messageBox_title[1024];
char input_messageBox_button_type[1024];
char input_messageBox_icon_type[1024];
char input_messageBox_do_display[1024];
char input_messageBox_clear_config[1024];

int messageBox_button_type = 0;
int messageBox_icon_type = 0;

int messageBox_icon_config = 0;
int messageBox_button_config = 0;

int messageBox_return_int = 0;
char messageBox_return_char[32];

DWORD CALLBACK Process(LPVOID data) {
	UNREFERENCED_PARAMETER(data);
	Sleep(100); // Let's let Rundll32 die

	SetEnvironmentVariable("messageBox_icon_type", "");
	SetEnvironmentVariable("messageBox_button_type", "");
	SetEnvironmentVariable("messageBox_text", "");
	SetEnvironmentVariable("messageBox_title", "");
	SetEnvironmentVariable("messageBox_do_display", "0");
	SetEnvironmentVariable("messageBox_clear_config", "0");
	SetEnvironmentVariable("messageBox_return", "0");

	while (TRUE) {
        GetEnvironmentVariable("messageBox_do_display", input_messageBox_do_display, 1024);
        GetEnvironmentVariable("messageBox_icon_type", input_messageBox_icon_type, 1024);
        GetEnvironmentVariable("messageBox_text", input_messageBox_text, 4096);
        GetEnvironmentVariable("messageBox_title", input_messageBox_title, 1024);
        GetEnvironmentVariable("messageBox_button_type", input_messageBox_button_type, 1024);
        GetEnvironmentVariable("messageBox_clear_config", input_messageBox_clear_config, 1024);

        if (strcmp(input_messageBox_icon_type, "messageBox_icon_error") == 0) { messageBox_icon_config = messageBox_icon_config | MB_ICONERROR; }
        if (strcmp(input_messageBox_icon_type, "messageBox_icon_warning") == 0) { messageBox_icon_config = messageBox_icon_config | MB_ICONEXCLAMATION; }
        if (strcmp(input_messageBox_icon_type, "messageBox_icon_info") == 0) { messageBox_icon_config = messageBox_icon_config | MB_ICONINFORMATION; }
        if (strcmp(input_messageBox_icon_type, "messageBox_icon_question") == 0) { messageBox_icon_config = messageBox_icon_config | MB_ICONQUESTION; }




        if (strcmp(input_messageBox_button_type, "messageBox_button_ok") == 0) { messageBox_button_config = messageBox_button_config | MB_OK; }
        if (strcmp(input_messageBox_button_type, "messageBox_button_yesno") == 0) { messageBox_button_config = messageBox_button_config | MB_YESNO; }
        if (strcmp(input_messageBox_button_type, "messageBox_button_okcancel") == 0) { messageBox_button_config = messageBox_button_config | MB_OKCANCEL; }
        if (strcmp(input_messageBox_button_type, "messageBox_button_retrycancel") == 0) { messageBox_button_config = messageBox_button_config | MB_YESNO | MB_OKCANCEL; }




        if (strcmp("0", input_messageBox_do_display) != 0) {
            SetEnvironmentVariable("messageBox_do_display", "0");
            messageBox_return_int = MessageBox(NULL, input_messageBox_text, input_messageBox_title, messageBox_icon_config | messageBox_button_config);
            _itoa_s(messageBox_return_int, messageBox_return_char, 10);
            SetEnvironmentVariable("messageBox_return", messageBox_return_char);
        }
        if (strcmp(input_messageBox_clear_config, "0") != 0) {
            messageBox_button_config = 0;
            messageBox_icon_config = 0;
            SetEnvironmentVariable("messageBox_clear_config", "0");
            SetEnvironmentVariable("messageBox_return", "0");
        }

		Sleep(1000 / 40);
	}
}

BasicDllMainImpl(Process);

//vars:
/*
messageBox_icon_type icon       (i)  messageBox_icon_error / messageBox_icon_warning / messageBox_icon_info / messageBox_icon_question
messageBox_button_type buttons  (i)  messageBox_button_ok / messageBox_button_yesno / messageBox_button_okcancel / messageBox_button_retrycancel
messageBox_text text            (i)
messageBox_title title          (i)
messageBox_clear_config         (i)
messageBox_do_display           (i)

messageBox_return               (o)
*/