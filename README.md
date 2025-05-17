# BealeCipher
This program encrypts and decrypts messages using the book cipher from the second page of the Beale Papers.

# How to use this program
## Understanding the arguments:
*{strings} are always text files names*
### Modes:  
   + -e = encode  
   + -d = decode  
### Encoding:  
*Either -b or -c is mandatory. -m is mandatory*
   + -b {string} = uses a book text file as key  
   + -c {string}:  
     + when used without -b, uses the specified key file as key
     + when used with -b, creates a key file from the book -b  
   + -m {string} = plain text message file to encode  
### Decoding:
*Either -b or -c is mandatory. -i is mandatory*
  + -b {string} = uses a book text file as key
  + -c {string} = uses a key file as key
  + -i {string} = encoded message text file to decode
  + -o {string} = names the file of the decoded message (optional)
### Examples:
1. Uses a book as a key, encrypt the *OriginalMessage* into the *CodedMessage* and saves the *KeyFile* in the format described later
```
./beale -e -b BookCipher -m OriginalMessage -o CodedMessage -c KeysFile 
```

2. Decrypts a message, using a *KeyFile* and outputs the *DecodedMessage* (which should be the same as *OriginalMessage* if used with the right *KeyFile*)
```
./beale -d -i CodedMessage  -c KeyFile -o DecodedMessage 
```

3. Decodes a message, using a book as a key and outputs the *DecodedMessage* (which should be the same as *OriginalMessage* if used with the right book)
```
./beale -d -i CodedMessage -b BookCipher -o DecodedMessage 
```

## The story behind the cipher
According to the legend, the three ciphertexts contain the location of a treasure worth approximately $43 Million USD. These ciphers were supposedly trusted to Robert Morriss by Thomas J. Beale who later disappeared, these papers were then passed to a friend of Morriss, who many years later in the 1880s, published them after not being able to solve the whole mystery. He did however solve the second paper, with the technique implemented here.

## How does it work
+ The cipher uses a book as a key to the cipher.  
+ Each word in the book is counted (starting from 0)
+ The first letter of each word is then represented by their count

**Using this text as a book key or book cipher, for example:**
```
In the beginning God created the heaven and the earth. And the earth was without form, and void; and darkness was upon
the face of the deep.
And the Spirit of God moved upon the face of the waters. And God said, Let there be light: and there was light.
```

**We would get this keys file:**
```
a: 7 10 16 18 27 39 46
b: 2 44
c: 4
d: 19 26
e: 9 12
f: 15 23 35
g: 3 31 40
h: 6
i: 0
l: 42 45 49
m: 32
o: 24 30 36
s: 29 41
t: 1 5 8 11 22 25 28 34 37 43 47
u: 21 33
v: 17
w: 13 14 20 38 48
```
> *The program will use negative numbers if they are missing from the book*

**And from it, we could write something like:**
```
0 -1 6 0 19 -1 1 6 0 29 -1 32 9 29 29 7 3 9
```
*"I hid this message"*
