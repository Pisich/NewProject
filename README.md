# PisiChBank
By Carlos Rodríguez (Pisich)

Banking platform built in C.</br></br>
Operations include:</br>
-Create a new account</br>
-Check the balance of your account</br>
-Deposit to your account</br>
-Withdraw from your account</br>
-Delete your account</br>

## Compiling
You can use any C compiler for this proyect, but I recommend you to use GCC.
```bash
# Clone the PisiCh Bank repo
git clone https://github.com/Pisich/PisiChBank

# Cd into the newly created folder
cd PisichBank

# Compile the code
gcc -o main.c PisiChBank
```
## Building the container
To build the container you must have docker installed in your system.</br>
If you already have it you can just follow these steps to build the container:
```bash
# Clone the PisiCh Bank repo
git clone https://github.com/Pisich/PisiChBank

# Cd into the newly created folder
cd PisichBank

# Build the container
docker build -t pisichbank:1.0 .

#Run the container
docker run pisichbank:1.0
```
The proyect is built inside an Alpine image. Inside it, there are some basic compiling and formatting tools that the proyect depends on.
## Contributions
Note that this program is in early development, if you would like to see a feature added, feel free to submit an issue or a pull request.
