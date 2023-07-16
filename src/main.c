#include <avr/io.h>
#include <util/delay.h>
#include <blink.h>
#include <lcd.h>

int main() {


    lcd_init(LCD_DISP_ON);
    lcd_clrscr();
    lcd_set_contrast(0x00);
    lcd_gotoxy(4,1);
    lcd_puts("Normal Size");
    lcd_charMode(DOUBLESIZE);

    DDRB |= (1 << PB0);
    int count = 0;
    char* count_string[20];
    while(1){
        blink();
        count++;
        lcd_gotoxy(0,2);
        lcd_charMode(NORMALSIZE);
        sprintf(count_string,"Counter %d",count);
        lcd_puts(count_string);
        _delay_ms(1000);
    }
}
