# head_table
This is a quick and dirty command line utility to display the head of a file, padded as a table. Most useful when piping into less:
```
./head_table test.csv | less -S
```
This displays a padded, scrollable table in your terminal of 10 lines from a csv file.

## Compilation

### Dependencies
This project depends on Boost, C++11 and gcc. If you already have boost, you can compile the project by doing:
```
bash compile.sh
```
