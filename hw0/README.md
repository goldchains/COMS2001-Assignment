
# HW 0: Executable #

## 1 Tools Overview

First, we will introduce you to some useful tools that make a good fit in any system programmer’s toolbox. Some of these (git, make) are MANDATORY to understand in that you won’t be able to compile/submit your code without understanding how to use them. Others such as gdb or tmux are productivity boosters; one helps you find bugs and the other helps you multitask more effectively. All of these are installed on the lab machines.  
We do not go into much depth on how to use any of these tools in this document. Instead, we refer to resources where you can read about them. (Links to these and additional resources can be found at the <a href="http://www.cs.wits.ac.za/ dmitry/coms2001/resources.html">course webpage</a>). We highly encourage this reading even though not all of it is necessary for this assignment. You will enjoy this course much more if you take time to master these tools, and they will serve you well in your future career.

### 1.1 git
**git** is a version control tool that helps keep track of your code. GitHub is a service that provides a place to host your code. You can use git on your own computer, without GitHub. Pushing your code to GitHub, however, lets you easily share it and collaborate with others.  
At this point, you have already tried out some of git commands, but to make full use of it, you need a much deeper understanding. Also, if you are serious about writing software, understanding the inner workings of git will be a huge benefit. If you have never used git or want a fresh start, we recommend
you start <a href="http://git-scm.com/book/en/Getting-Started">here</a>. If you sort of understand git, this <a href="http://goo.gl/cLBs3D">presentation</a> and this <a href="http://think-like-a-git.net/">website</a> will be useful in understanding the inner workings a bit more.

### 1.2 make
**make** is a utility that automatically builds executable programs and libraries from source code by reading files called makefiles, which specify how to derive the target program. In a makefile, you list dependencies among your files, and make traverses the dependency graph to build everything. Unfortunately, make has very awkward syntax that is, at times, very confusing if you are not properly equipped to understand
what is actually going on.  
A few good tutorials are <a href="ttp://wiki.wlug.org.nz/MakefileHowto">here</a> and <a href="http://mrbook.org/blog/?s=make">here</a>.

### 1.3 gdb
Debugging C programs is difficult. Crashes don’t give you nice exception messages or stack traces by default. Fortunately, there’s gdb. If you compile your programs with a special flag **-ggdb3**, then the output executable will have debug symbols, which allow gdb to do its magic. If your run your C program inside gdb it will allow you to not only look get a stack trace, but inspect variables, change variables, pause code, among other things.  
Normal gdb has a very plain interface, so you might prefer to use **cgdb**, which has syntax highlighting and few other features.  
<a href="http://rsquared.sdf.org/gdb/">This</a> is an excellent read on understanding not only how to use gdb, but also how your programs work. The material discussed in this tutorial links up with concepts we are going to be discussing from the very beginning of this course, so reading it will significantly enhance your understanding of the course material.  
At this point, take a moment to begin working on your wc program for this assignment. Provide the **-ggdb3** flag when you compile your program with gcc. Start the program under gdb. Set a break point at the beginning of main. Run to there. Try out various commands. Figure out how to pass command line arguments. Add local variables and try probing their values. Learn about step, next, and break.

### 1.4 Text-Editors
There are two very powerful terminal-based text editors: **emacs** and **vim**. Learning to use one of these takes time but will dramatically boost your productivity in the long run. We encourage you to use one of these for the duration of the course, or at least a simple alternative with syntax highlighting, such as **Notepad++**. Learning to code independent of an IDE is very important. <a href="http://www.jesshamrick.com/2012/09/10/absolute-beginners-guide-to-emacs/">Here</a> is a good tutorial to get started with **emacs**.

## 2 git

As stated [before](../README.md), to do this, and all the subsequent assignments, you need to have a GitHub account set up. Therefore, if you have not done so already, go to https://github.com and create an account.  
To start working on this assignment, clone the repository hw into your local directory, and change to the directory hw/hw0 to get access to the files for this assignment:
```
git clone https://github.com/WITS-COMS2001/hw.git
cd hw/hw0
ls
```

You are recommended to create a hw repository on your own account for working, and use the one we assign you for your final submission.

Say you've just finished coding wc.c in the first part of your assignment. You should *commit*, this saves the changes you've made on your local files.  
First you have to *add* the files you want to commit, you can see what files are changed displayed in red by executing: ```git status```  
You can also see what changes have been made since your last commit: ```git diff```  
To add files to your next commit do ```git add wc.c```, you can also add all changed files by doing ```git add .```  
Once you've done this, *status* should show these files in green. Now you have to commit those files: ```git commit -m "Finished coding wc.c."```. The -m flag specifies a commit message as a parameter, you don't have to use the flag but you should always indicate what you've done as the message.  
You can view your commit history by running ```git log```.
But the files still saved only on the local computer, to update the remote repository, you need to *push* the repository: ```git push <your_repository_url> master```.
Having done that once, you can continue doing your work next time by cloning the hw repository from your GitHub account on another computer.
If you just type ```git push```, it will try to push to origin. Unless you changed origin to point to your personal GitHub url as specified in hw/README.md, this will fail.

## 3 Your assignment

For this homework, you will be brushing up on your C skills and exploring how a compiled executable is structured.  
Part of this course is that you are able solve problems independently. We have linked some resources and you are encouraged to read the material and search the internet for any specific problems you encounter; Googling is a skill. Nevertheless, your tutors are available should you get stuck.

### 3.1 make
You have probably been using **gcc** to compile your C++ programs from the command line in first year, but this grows tedious and complicated as the number of files you need to compile increases. You will need to write a Makefile that compiles main.c, wc.c, and map.c. You will also need to write a target clean (to be invoked by make clean) to remove your binaries. If all of this is new to you, make sure to consult the following tutorial: http://mrbook.org/blog/?s=make

### 3.2 wc
We are going to use wc.c to get you thinking in C, with an eye to how applications utilize the operating system by passing command line arguments from the shell, reading and writing files, and standard file descriptors. You might be familiar with these concepts from your earlier courses, but this course will cover them in much more depth.  
Your first task is to write a clone of the Unix tool wc, which counts the number of words inside a particular text file. You can run Unix’s wc to see what your output should look like, and try to mimic its basic functionality in wc.c (don’t worry about the flags or spacing in the output). 
You should also familiarise yourself with the *man* command, which allows you to access manual pages for Linux terminal functions. e.g. ```man wc```  
While you are working on this, take the time to get some experience with gdb. Use it to step through your code and examine variables. If you have never used gdb before, consult the following tutorial: http://dirac.org/linux/gdb/

Since this is your first assignment, we'll help introduce you to some parts of C that you may not have experienced hitherto.

You will notice that main takes in two parameters: *argc* and *argv*.  
*argv*: the array of parameters passed to the program. For example you may call *wc* as follows: ```wc file.txt```. *argv* is then ["wc","file.txt"].  
*argc*: the number of parameters passed to the program and will always be at least 1, since the program name is always the first parameter.

Another thing to note in C is that you do not use streams in the C++ sense. Printing output in C may be done as follows:
```
int val2 = 2001;
char word[] = "student"
printf("I am a %s doing COMS%d",word,val2);
```  
The format options presented above are string (%s) and signed integer (%d). We have listed seveal good tutorial and reference sites for C at http://www.cs.wits.ac.za/~dmitry/coms2001/resources.html  
You should consult those for techniques such as file handling.

### 3.3 Executables and addresses
Now that you have dusted off your C skills and got familiarity with some of the tools, we want you to understand what is really inside of a running program and what the operating system needs to deal with. Load up your wc executable in gdb with a single input file command line argument, set a breakpoint at wc, and run to there. Take a look at the stack using where or backtrace (bt). While you are looking through gdb, think about the following questions and put your answers in the file gdb.txt. • What is the value of infile? (hint: print infile)
* What is the object referenced by infile? (hint: *infile)
* What is the value of ofile? How is it different from that of infile? Why?
* What is the address of the function wc?
* Try info stack. Explain what you see.
* Try info frame. Explain what you see.
* Try info registers. Which registers are holding aspects of the program that you recognize?  

We have just peeled away the abstraction layers that is the onion of an executing program: the source
code, compiled into an object, linked into a executable, that is loaded and executed on a computer. The
operating system meets the application as an executable file when you run it. There is more to the
executable than meets the eye. Let’s look down inside.  

```objdump -x wc```

You will see that it has several segments, names of functions and variables in your program correspond to labels with addresses or values, and the guts of everything is chunks of stuff within segments. While you are looking through the objdump, try and think about the following questions and put
the answers in the file objdump.txt.  
* What file format is used for this binary? What architecture is it compiled for?
* What are the names of segments you find?
* What segment contains wc (the function) and what is its address? (hint: ```objdump -w wc | grep
wc```)
* What about main?
* How do these correspond to what you observed in gdb when you were looking at the loaded,
executing program?
* Do you see the stack segment anywhere? What about the heap? Explain.

OK, now you are ready to write a program that reveals its own executing structure. The second file in hw0, map.c provides a rather complete skeleton. You will need to modify it to get the addresses that you are looking for and get the type casts right so that it compiles without warning. The output of the solution looks like the following (the addresses will be different).
>precise64 hw0 ./map  
>Main @ 40058c  
>recur @ 400544  
>Main stack: 7fffda11f73c  
>static data: 601028  
>Heap: malloc 1: 671010  
>Heap: malloc 2: 671080  
>recur call 3: stack@ 7fffda11f6fc  
>recur call 2: stack@ 7fffda11f6cc  
>recur call 1: stack@ 7fffda11f69c  
>recur call 0: stack@ 7fffda11f66c  

Now think about the following questions and put the answers in map.txt.
* Using objdump on the map executable. Which of the addresses from the previous section are defined in the executable, and which segment is each defined in?
* Make a list of the important segments, and what they are used for.
* What direction is the stack growing in?
* How large is the stack frame for each recursive call?
* Where is the heap? What direction is it growing in?
* Are the two malloc()ed memory areas contiguous?
* Make a high level map of the address space for the program containing each of the important segments, where they start and end, where the holes are, and what direction things grow in.

### 3.4 user limits
The size of the dynamically allocated segments, stack and heap, is something the operating system has to deal with. How large should these be? Poke around a bit to find out how to get and set user limits on linux. Modify main.c so that it prints out the maximum stack size, the maximum number of processes,
and maximum number of file descriptors. Currently, when you compile and run main.c you will see it print out a bunch of system resource limits (stack size, heap size, ..etc). Unfortunately all the values will be 0! Your job is to get this to print the ACTUAL statistics. (Hint: ```man rlimit```)  
You should expect output similar to this:
```
$make
$./main
stack size: 8192
process limit: 2782
max file descriptors: 1024
$echo $?
0
```

The final command ```echo $?``` returns the error code of the last executed command; 0 = success, anything else usually means something went wrong.

## 3 Submitting your work

You will be saving all your work on your assigned GitHub account, these will be created some time before the next lab session.
Once you have finished your work on your local repository, push to your assigned GitHub account, which will be named after your student number. 
e.g ```git push https://github.com/WITS-COMS2001/100234 master```



**Good luck with your first assignment!**