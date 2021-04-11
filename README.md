# CF-plag-checker

This project when run fetches the code submitted by specified users for a particular codeforces contest and finds if there is plagiarism 
by using [MOSS](https://theory.stanford.edu/~aiken/moss/) Plagiarism Checker.

### How does it work
This project uses the best plagiarism checker available online i.e [MOSS](https://theory.stanford.edu/~aiken/moss/) with Selenium WebDriver in Node.js to 
scrape out the code submissions of users and detect plagiarism.

### How to run
+ Feed the participants username in participants.json
+ Make a .env file and enter 

```
  ContestCode=1466
  
  Problem=4
```
+ Install all the dependencies
```
npm i
```
+ Run the server
```
npm start
```
+ All code will be fetched and saved in submitted_codes folder.
+ Now run `node moss-plagiarism.js` to get the urls of the plagiarism codes in moss_urls.json. This process might take some time, please be patient.

Contributions to this project are welcome :)
