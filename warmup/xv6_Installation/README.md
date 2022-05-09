## xv6 Installation

**Note: Only for OS Internals Track**

Xv6 is a teaching operating system and was developed in MIT. A vital fact about Xv6 is that it contains all the core Unix concepts and has a similar structure to Unix even though it lacks some functionality that you would expect from a modern operating system. This is a lightweight operating system where the time to compile is very low. The future assignments in the OS Internals Track will require you to use xv6 for various implementations.

### Setting up your system for OS Internals Track

Please make sure you are on a recent LTS version of **Ubuntu** (Ubuntu 18.04/20.04/22.04) before proceeding.

```console
# Install all the required packages
sudo apt-get update
sudo apt -y install build-essential gdb coreutils util-linux sysstat procps wget tar qemu
    
# Clone and Initialize Xv6
wget https://www.cse.iitb.ac.in/~mythili/os/labs/xv6-public.tgz 
tar -xf xv6-public.tgz
cd xv6-public 
make

# Run xv6 to ensure everything has been setup correctly and make sure you are in xv6-public directory
make qemu-nox

# If the output ends with:
init: starting sh
$

# run ls command
ls
# something like below will be printed on screen.
.              1 1 512
..             1 1 512
README         2 2 2286
cat            2 3 15492
echo           2 4 14376
forktest       2 5 8812
grep           2 6 18328
init           2 7 14996
kill           2 8 14460
ln             2 9 14356
ls             2 10 16924
mkdir          2 11 14484
rm             2 12 14464
sh             2 13 28512
stressfs       2 14 15392
usertests      2 15 62884
wc             2 16 15912
zombie         2 17 14032
console        3 18 0

# You're done! Exit QEMU with Ctrl+A X
# Ctrl+A X means 1. First press Ctrl + A (A is just key a, not the alt key), 2. then release the keys, 3. afterwards press X.
```

Note: If you are getting an error in the installation steps, please visit the [_FAQ_](README.md#faq) section.

### Windows 10
Configure Windows Subsytem for Linux (WSL) by following the official Instructions [here](https://docs.microsoft.com/en-us/windows/wsl/install-win10). Choose **Ubuntu** as the Linux variant and then follow the instructions for [Ubuntu](README.md#setting-up-your-system-for-os-internals-track) above.

#### Windows 7/8 or macOS
It is recommended to either:
- [dual-boot Ubuntu](https://www.howtogeek.com/214571/how-to-dual-boot-linux-on-your-pc/) or,
- run it as a [VM](https://itsfoss.com/install-linux-in-virtualbox/).

Follow the steps for [Ubuntu](README.md#setting-up-your-system-for-os-internals-track) above when you’re done!


### FAQ

**Que**. make qemu-nox throws this error: "Couldn't find a working QEMU executable"

**Ans**. Sometimes, the default qemu package does not configure itself properly. Try installing the complete set of binaries for x86:

<code>sudo apt install qemu-system-x86</code>

and retry.
Alternatively, if you are running Ubuntu directly on your machine (not on a VM/hypervisor), you can also install qemu-kvm

<code>sudo apt install qemu-kvm</code>

Please do not modify xv6-public's source by yourself, this can cause problems.

**Que**. Can I use macOS directly without running a VM over it? 

**Ans**. Not recommended, some further weeks need linux-specific features. Even for xv6 labs, you'll need a cross compiler to modify xv6 code, which can be significantly harder to debug.

**Que**. How to quit the QEMU monitor when not using a GUI?

**Ans** . [https://superuser.com/a/1211516](https://superuser.com/a/1211516)

**Que**. make qemu-nox throws this error: "error: writing 1 byte into a region of size 0 [-Werror=stringop-overflow=]"

**Ans**. Edit makefile and add : CFLAGS += -Wno-stringop-overflow (
[link](https://www.reddit.com/r/ManjaroLinux/comments/p4445x/comment/hv06t00/?utm_source=share&utm_medium=web2x&context=3))