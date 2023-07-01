#include <stdio.h>
#include <stdint.h>
#include <time.h>

void leerRegistroRTC(int registro) {
    // Leer el valor del RTC
    time_t t = time(NULL);
    struct tm *rtc_time = localtime(&t);
    uint8_t valor = 0;

    switch (registro) {
        case 0:
            valor = rtc_time->tm_sec;
            break;
        case 1:
            valor = rtc_time->tm_min;
            break;
        case 2:
            valor = rtc_time->tm_hour;
            break;
        case 3:
            valor = rtc_time->tm_mday;
            break;
        case 4:
            valor = rtc_time->tm_mon + 1;
            break;
        case 5:
            valor = rtc_time->tm_year % 100;
            break;
        case 6:
            valor = rtc_time->tm_wday;
            break;
        case 7:
            valor = rtc_time->tm_yday + 1;
            break;
        case 8:
            valor = rtc_time->tm_isdst;
            break;
        case 9:
            valor = rtc_time->tm_gmtoff;
            break;
        case 10:
            valor = rtc_time->tm_zone;
            break;
        case 11:
            valor = rtc_time->tm_gmtoff / 3600;
            break;
        case 12:
            valor = rtc_time->tm_gmtoff / 60 % 60;
            break;
        case 13:
            valor = rtc_time->tm_gmtoff % 60;
            break;
        default:
            printf("Registro no válido.\n");
            return;
    }

    // Imprimir el valor en hexadecimal
    printf("Valor del registro %d: 0x%02X\n", registro, valor);
}

int main() {
    int registro;

    printf("Ingrese el número de registro (0-13): ");
    scanf("%d", &registro);

    leerRegistroRTC(registro);

    return 0;
}
