/******************************************************************************/
/*** General Utility                                                        ***/    
/*** Ver 1.40                                                               ***/
/*** Date: 13920627                                                         ***/
/*** Copyleft (c) 2013 by O. Farzadian, M. Zarepour, A. Alipour,            ***/
/*** and M. Mortazavi Rad. All lefts reserved.                              ***/
/*** Licensed under The GNU General Public License v3.0                     ***/
/*** Code implemented in GNU C++ compiler (v. 4.6.3) in 64-bit UBUNTU 12.04 ***/
/*** Run under a Intel® Core™ i3-2330M CPU @ 2.20GHz × 4 machine with 2 GB  ***/
/*** RAM.                                                                   ***/
/******************************************************************************/

#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
//------------------------------------------------------------------------------
// wait()
#ifdef __linux__
  #include <termios.h>
#elif _WIN32 || _WIN64
#else
  #error OS not supported
#endif
// wait()
//------------------------------------------------------------------------------
#include "../include/utils.h"

using namespace std;

//------------------------------------------------------------------------------
// wait()
#ifdef __linux__
  //‎ ‫تنظیمات جدید ترمینال را فعال می‌کند.
  void InitTerm(bool echo, struct termios& TerminalState) {
    tcgetattr(0, &TerminalState);           // ‫تنظیمات ورودی/خروجی ترمینال را دریافت می‌کند.
    struct termios newt = TerminalState;    // ‫به تنظیمات جدید مقدار اولیه می‌دهد.
    newt.c_lflag &= ~ICANON;                // ‫بافر ورودی/خروجی را غیر فعال می‌کند.
    if (echo)
        newt.c_lflag |= ECHO;    // ‫echo مد را تنظیم می‌کند.
    else    
        newt.c_lflag &= ~ECHO;    // ‫echo مد را تنظیم می‌کند.
    newt.c_lflag &= echo ? ECHO : ~ECHO;    // ‫echo مد را تنظیم می‌کند.
    tcsetattr(0, TCSANOW, &newt);           // ‫تنظیمات جدید را فعال می‌کند.
  }

  //‎ ‫تنظمیات قدیمی ترمینال را برمی‌گرداند.
  void RestoreTerm(struct termios& TerminalState) {
    tcsetattr(0, TCSANOW, &TerminalState);
  }

  // Read 1 character from consul (echo defines echo mode)
  char __getch(bool echo) {
    struct termios OldTerminalState;
    InitTerm(echo, OldTerminalState);
    char ch = getchar();
    RestoreTerm(OldTerminalState);
    return ch;
  }

  // Read 1 character from consul without echo
  char getch(void) {
    return __getch(false);
  }

  // Read 1 character  from consul with echo
  char getche(void) {
    return __getch(true);
  }

  // pause consul (terminal) till press any key
  void __wait() {
      cout << "Press any key to continue ...";
      getch();
      cout << endl;
  }
#elif _WIN32 || _WIN64
  // pause consul (terminal) till press any key
  void __wait() {
      system("pause");  
  }
#else 
  void __wait() {
      cerr <<  "wait rutin not supported in current OS" << endl;
  }
#endif
// wait()
//------------------------------------------------------------------------------

