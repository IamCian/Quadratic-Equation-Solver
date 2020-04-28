# Quadeq (Quadratic Sequence)
Gets the Nth term for a quadratic sequence.

# License
Licensed under the [MIT License](https://github.com/IamCian/quadeq/blob/master/LICENSE).
See [https://choosealicense.com/licenses/mit/](https://choosealicense.com/licenses/mit/)

# Usage
```console
$ quadeq --help
Usage: quadeq [-w show_workings] TERMS
Get the Nth term for a quadratic sequence
Example: quadeq -w 1 3 9 19
$ quadeq 1 3 9 19
Tn=2n^2-4n+3
$ quadeq -w 1 3 9 19
First differences: 2 6 10
Second difference: 4
Divide by 2: 2
|2n^2 |Sequence |Difference |
|2    |1        |-1         |
|8    |3        |-5         |
Difference between differences: -4
Difference as sequence: Tn=-4n+3
Tn=2n^2-4n+3
```

# Installation
Installs to __/usr/local/bin/quadeq__ by default.
```console
$ git clone https://github.com/IamCian/quadeq.git quadeq
$ cd quadeq
$ make
$ sudo make install
```
**Removal**
```console
$ sudo make uninstall
```
or
```console
$ sudo rm /usr/local/bin/quadeq
```
