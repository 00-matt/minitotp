A list of things that need to be done, in no particular order:

* Implement HMAC-SHA-256 and HMAC-SHA-512
* Drop OpenSSL dependency
  * It is fat
  * We only need SHA1, SHA256, SHA512 and a HMAC function
* Write man pages
  * For library methods
  * For CLI application
* Document build/installation process
  * And all requirements, dependencies, etc.
