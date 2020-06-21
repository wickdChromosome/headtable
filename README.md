# head_table
This is a quick and dirty command line utility to display the head of a file, padded as a table - most useful when piped into less:
```
./headtable test.csv | less -S
```
This displays a padded, scrollable table in your terminal of 10 lines from a csv file.

To do this for 200 lines:
```
./headtable test.csv 200 | less -S
```

## Compilation

### Dependencies
This project depends on Boost, C++11 and gcc.
On debian, you can get the deps by doing:
```
sudo apt install gcc libboost1.67-dev
```



### Now compile

```
bash compile.sh
```

### Install the binary system-wide

```
sudo bash install.sh
```
