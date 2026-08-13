# fictional-pancake-C-
Figuring out C and putting it to the test with mini-projects. ^^



 ## birthday calculator.. 
 A small C program that takes a person's date of birth — with full input
validation, including leap-year-aware day limits — and calculates the
day of the week it fell on, using **Zeller's Congruence**.

## Why it's useful

Naively validating a date is easy to get wrong (accepting `31/2/2023`,
`30/2/2024`, or non-numeric input). This program:

- Rejects impossible dates (e.g. February 31st, or the 30th in a
  30-day-max month) by computing the correct day limit *before*
  asking for the day.
- Correctly identifies leap years using the standard Gregorian rule
  (`year % 4 == 0 && year % 100 != 0` OR `year % 400 == 0`).
- Rejects non-numeric input without crashing or looping forever.
- Calculates the weekday using Zeller's Congruence, a constant-time
  modular arithmetic formula (no lookup tables, no date libraries).

## How Zeller's Congruence works

For the Gregorian calendar:

```
h = (q + floor(13(m+1)/5) + K + floor(K/4) + floor(J/4) - 2J) mod 7
```

Where:
- `q` = day of the month
- `m` = month, with January and February treated as months 13 and 14
  of the *previous* year
- `K` = year of the century (`year % 100`)
- `J` = zero-based century (`year / 100`)
- `h` = 0 → Saturday, 1 → Sunday, ... 6 → Friday

This implementation uses the `+5J` variant instead of `-2J`
(mathematically equivalent after mod 7) to avoid C's `%` operator
producing negative results on negative operands.  

                                                                  END 
