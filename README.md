# Simple Shell
This is a simple emulation program for the BASH Shell
## Description
This project replicates the functionality of the BASH shell for simple commands and some built-ins.  \
Many BASH Commands and built-ins are not yet implemented. \
Please see the usage section for details of implemented built-ins.
## Usage
To Run the shell  use:
```bash
./hsh
```
Once the shell opens you will be presented with a prompt that is the dollar sign (“$”), \
and you can use simple commands and their flags such as:
### Examples
```
$ ls -la
drwxr-xr-x 6 jswini jswini  4096 Aug 25 13:40 .
drwxr-xr-x 7 jswini jswini  4096 Aug 25 13:25 ..
drwxr-xr-x 8 jswini jswini  4096 Aug 25 13:25 .git
-rw-r--r-- 1 jswini jswini    78 Aug 23 14:26 .gitignore
```

Other implemented built-ins include: exit and env.
 
## Roadmap
We intend to implement other built-ins, and try to use our own getline function, \
as well as cd to change directories, and arguments to the exit built in.
 
## Authors and acknowledgment
Hope Parnell (3251@holbertonschool.com)\
Jeffrey Winikoff (2677@holbertonschool.com)
 
## License
We don’t have a license.
 
## Project status
As noted in the roadmap we hope to get more functionality into this shell before the project deadline.

