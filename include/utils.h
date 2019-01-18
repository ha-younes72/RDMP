/******************************************************************************/
/*** General Utility                                                        ***/    
/*** Ver 1.41                                                               ***/
/*** Date: 13920628                                                         ***/
/*** Copyleft (c) 2013 by O. Farzadian, M. Zarepour, A. Alipour,            ***/
/*** and M. Mortazavi Rad. All lefts reserved.                              ***/
/*** Licensed under The GNU General Public License v3.0                     ***/
/*** Code implemented in GNU C++ compiler (v. 4.6.3) in 64-bit UBUNTU 12.04 ***/
/*** Run under a Intel® Core™ i3-2330M CPU @ 2.20GHz × 4 machine with 2 GB  ***/
/*** RAM.                                                                   ***/
/******************************************************************************/

#ifndef UTILS_H

#define UTILS_H

//#define DEBUG_MODE                        // ‫استفاده از این تعریف در برنامه می‌تواند حالت دیباگ را فعال کند.
//#define NO_WAIT                           // ‫ استفاده از این تعریف در برنامه می‌تواند برای اجرای برنامه بدون
                                            //‎ ‫  وقفه استفاده شود.
                                            //‎ ‫البته لازم است این تعاریف قبل از فراخوانی هدر کتابخانه 
                                            //‎ ‫utils.h آورده شود.
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>
#ifdef _WIN32
  #include <conio.h>
#endif
#ifdef _WIN64
  #include <conio.h>
#endif

//------------------------------------------------------------------------------
// math routine
const float pi = 3.14159265359;             // ثابت پی

template <typename Number>                  // نوع داده برای انواع اعداد
inline Number sqr(Number x) { return x*x; }

template <typename Number>                  // نوع داده برای انواع اعداد
inline Number ipow(Number base, int exp) {  // تابع بهینه توان با نمای صحیح
    if (exp >= 0) {
        Number result = 1.0;
        while (exp) {
            if (exp & 1)
                result *= base;
            exp >>= 1;
            base *= base;
        }
        return result;
    } else
        return 1.0 / ipow(base, -exp);
}
// math routine
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// wait() - ترمینال (کونسول) را تا زمانی که یک کلید فشرده شود متوقف می‌کند. این
//‎                                        .دستور مستقل از سیستم عامل است
// pause consul (terminal) till press any key
#ifdef __linux__
  char getch(void); 
  char getche(void);
#endif
#ifdef NO_WAIT
  inline void wait() { std::cout << "NO_WAIT definition disable wait() routine" << std::endl; }
#else
  inline void wait() { 
      void __wait();
      __wait(); 
  }
#endif
// wait()
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// DEBUG_MODE
#ifdef DEBUG_MODE
  #define DEBUG(X) { X; }
  #define NODEBUG(X) ; /* Nothing */
#else
  #define DEBUG(X) ; /* Nothing */
  #define NODEBUG(X) { X; }
#endif
// DEBUG_MODE
//------------------------------------------------------------------------------

#endif
