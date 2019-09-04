A list of things that need to be done, in no particular order:

* Separate HOTP (RFC 4226) and TOTP (RFC 6238) implementations
* Allow caller to change options
  * Hash function
  * Key length
  * Time step
* Drop OpenSSL dependency
  * It is fat
  * We only need SHA1, SHA256, SHA512 and a HMAC function
* Write man pages
  * For library methods
  * For CLI application
* Document build/installation process
  * And all requirements, dependencies, etc.
