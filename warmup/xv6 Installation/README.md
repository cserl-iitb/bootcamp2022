## xv6 Installation

**Note: Only for OS Internals Track**

Xv6 is a teaching operating system and was developed in MIT. A vital fact about Xv6 is that it contains all the core Unix concepts and has a similar structure to Unix even though it lacks some functionality that you would expect from a modern operating system. This is a lightweight operating system where the time to compile is very low. The future assignments in the OS Internals Track will require you to use xv6 for various implementations.

### Useful References

[xv6 Installation Document](https://docs.google.com/document/d/e/2PACX-1vR8AvZU9KeGoMAKwSfEcjk4uHf465C0cHefGlGRZlZq8kBlnetMwx9x0h2JwqmJM5KqX_lnVfIFqd_m/pub) (google doc web version)

### Setting up your system for OS Internals Track

Please make sure you are on a recent LTS version of Ubuntu (Ubuntu 18.04/20.04/22.04) before proceeding.

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

# You're done! Exit QEMU with Ctrl+A X
# Ctrl+A X means 1. First press Ctrl + A (A is just key a, not the alt key), 2. then release the keys, 3. afterwards press X.
```

Note: If you are getting an error in the installation steps, please visit the FAQ section on [this](https://docs.google.com/document/d/e/2PACX-1vR8AvZU9KeGoMAKwSfEcjk4uHf465C0cHefGlGRZlZq8kBlnetMwx9x0h2JwqmJM5KqX_lnVfIFqd_m/pub) page.