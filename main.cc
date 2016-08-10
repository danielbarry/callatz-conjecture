#include <iostream>
#include <stdexcept>
#include <string>

#define DEBUG 0

static void compute(unsigned __int128 n, unsigned __int128 l, unsigned __int128 u);
static void printNum(unsigned __int128 n);
static unsigned __int128 charArrTou128(char* s);
static std::string u128ToCharArr(unsigned __int128 n);

static unsigned __int128 U128_MAX;
static unsigned __int128 U128_CALC_MAX;

/**
 * main()
 *
 * Gets input from the user and sets up the main program.
 *
 * @param argc The number of arguments passed.
 * @param argv The arguments passed from the command line.
 * @return The exit code for the program.
 **/
int main(int argc, char** argv){
  /* Work out constants on the fly */
  U128_MAX = 0;
  --U128_MAX;
  U128_CALC_MAX = (U128_MAX - 1) / 3;
  /* Temporary variables */
  std::string::size_type sz;
  unsigned __int128 n = 0;
  unsigned __int128 c = 0;
  unsigned __int128 l = 0;
  unsigned __int128 u = 0;
  /* Number of arguments changes the mode */
  switch(argc){
    case 2 :
      /* Convert the number */
      n = charArrTou128(argv[1]);
      /* Run the computation */
      compute(n, 1000, 10000);
      break;
    case 3 :
      /* Convert the number */
      n = charArrTou128(argv[1]);
      c = charArrTou128(argv[2]);
      /* Run the computation */
      while(c > 0){
        compute(n, 1000, 10000);
        --n;
        --c;
      }
      break;
    case 4 :
      /* Convert the number */
      n = charArrTou128(argv[1]);
      c = charArrTou128(argv[2]);
      l = charArrTou128(argv[3]);
      /* Run the computation */
      while(c > 0){
        compute(n, l, 10000);
        --n;
        --c;
      }
      break;
    case 5 :
      /* Convert the number */
      n = charArrTou128(argv[1]);
      c = charArrTou128(argv[2]);
      l = charArrTou128(argv[3]);
      u = charArrTou128(argv[4]);
      /* Run the computation */
      while(c > 0){
        compute(n, l, u);
        --n;
        --c;
      }
      break;
    default :
      std::cout << "Use:" << '\n';
      std::cout << "  cc <N>" << '\n';
      std::cout << "  cc <N> <C>" << '\n';
      std::cout << "  cc <N> <C> <L>" << '\n';
      std::cout << "  cc <N> <C> <L> <U>" << '\n';
      std::cout << "N is the start number, no default" << '\n';
      std::cout << "C is negative count, default is 1" << '\n';
      std::cout << "L is the limit number, default is 1000" << '\n';
      std::cout << "U is the upper number, default is 10000" << '\n';
      break;
  }
  /* Always return good */
  return 0;
}

/**
 * compute()
 *
 * Compute the number is found - then log the output.
 *
 * @param n The number to be computed.
 * @param l The number to reach before printing the result.
 * @param u The upper limit on the computation.
 **/
static void compute(unsigned __int128 n, unsigned __int128 l, unsigned __int128 u){
  /* Store original number */
  unsigned __int128 o = n;
  /* Counter for number of operations */
  int c = 0;
  /* Loop until we hit one or we hit a high number */
  while(n > 1 && c < u){
    if(n & 1 == 1){
      /* n=3n+1 */
      n += n + n;
      ++n;
      /* Increment our count */
      ++c;
      #if DEBUG == 1
        printNum(n);
      #endif
      /* NOTE: This always results in an even number. */
    }
    /* n=n/2 */
    n >>= 1;
    /* Increment our count */
    ++c;
    #if DEBUG == 1
      printNum(n);
    #endif
  }
  /* Output our final result if it's significant */
  if(c >= l){
    std::cout << u128ToCharArr(o) << '\t' << u128ToCharArr(c) << '\n';
  }
}

/**
 * printNum()
 *
 * Prints the current number.
 *
 * @param n The number to be printed.
 **/
static void printNum(unsigned __int128 n){
  std::cout << u128ToCharArr(n) << '\n';
}

/**
 * charArrTou128()
 *
 * Converts char* to unsigned __int128 via a manual conversion.
 *
 * NOTE: This method fails silently.
 *
 * @param s The string to be converted.
 * @return The converted number.
 **/
static unsigned __int128 charArrTou128(char* s){
  unsigned __int128 r = 0;
  int x = 0;
  while(s[x] != '\0'){
    unsigned __int128 o = r;
    r *= 10;
    r += (int)(s[x]) - 48;
    if(r <= o){
      /* Overflow detected */
      throw std::overflow_error("string too large for unsigned __int128 conversion");
    }
    ++x;
  }
  return r;
}

/**
 * u128ToCharArr()
 *
 * Converts unsigned __int128 to char* via a manual conversion.
 *
 * @param n The number to be converted.
 * @return The converted string.
 **/
static std::string u128ToCharArr(unsigned __int128 n){
  if(n > 0){
    /* TODO: Increase the efficiency of this loop. */
    std::string s = "";
    while(n > 0){
      s.insert(0, 1, (char)(((int)'0') + (n % 10)));
      n /= 10;
    }
    return s;
  }else{
    return "0";
  }
}
