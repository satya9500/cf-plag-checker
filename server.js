const {Builder, By, Key, until} = require('selenium-webdriver');
require('dotenv').config();
const fs = require('fs');
let participants = fs.readFileSync('participants.json');
participants = JSON.parse(participants).username;

const langMap = [
    {
        name: 'Python 3',
        extension: 'py'
    },
    {
        name: 'PyPy 3',
        extension: 'py'
    },
    {
        name: 'Python 2',
        extension: 'py'
    },
    {
        name: 'PyPy 2',
        extension: 'py'
    },
    {
        name: 'GNU C++11',
        extension: 'py'
    },
    {
        name: 'GNU C++14',
        extension: 'py'
    },
    {
        name: 'GNU C++17',
        extension: 'py'
    },
    {
        name: 'JavaScript',
        extension: 'js'
    },
    {
        name: 'Java 8',
        extension: 'java'
    },
    {
        name: 'Java 11',
        extension: 'java'
    }
];

const findExtension = (codeLanguage) => {
    for(let element of langMap) {
        if(element.name === codeLanguage)
            return element.extension;
    }
    return 'txt';
}

const init = async function example() {
    let driver = await new Builder().forBrowser('firefox').build();
    try {
    //   await driver.get('https://codeforces.com/enter');
    //   await driver.findElement(By.name('handleOrEmail')).sendKeys(process.env.EMAIL, Key.RETURN);
    //   await driver.findElement(By.name('password')).sendKeys(process.env.PASSWORD, Key.RETURN);
    //   let loginBtn = await driver.findElement(By.xpath(`//*[@id="enterForm"]/table/tbody/tr[4]/td/div[1]/input`));
    //   await driver.executeScript("arguments[0].click();",loginBtn);
    //   await driver.get(`https://codeforces.com/contest/${process.env.ContestCode}/standings`);
    // await driver.get(`https://codeforces.com/contest/${process.env.ContestCode}/status/${process.env.Problem}`);
    
    const submissionUrl = [];

    for(participant of participants) {
        await driver.get(`https://codeforces.com/contest/${process.env.ContestCode}/status/${process.env.Problem}`);
        await (await driver.findElement(By.name("participantSubstring"))).clear();
        await driver.findElement(By.name("participantSubstring")).sendKeys(participant, Key.RETURN);
        await driver.get(`https://codeforces.com/contest/${process.env.ContestCode}/status/${process.env.Problem}`);
        const url = await driver.findElement(By.className(`view-source`)).getAttribute('href');
        driver.get(url);
        submissionUrl.push(url);
        const code = await (await driver.findElement(By.className('prettyprint'))).getText();
        console.log(code);
        let codeLanguage = await (await driver.findElement(By.xpath('//*[@id="pageContent"]/div[2]/div[6]/table/tbody/tr[2]/td[4]'))).getText();
        console.log(codeLanguage);
        codeLanguage = findExtension(codeLanguage)
        console.log(codeLanguage);
        // let createStream = await fs.createWriteStream(`submitted_code/problem${process.env.Problem}_solution/${participant}.${codeLanguage}`);
        // createStream.end();
        // let writeStream =  await fs.createWriteStream(`submitted_code/probelm${process.env.Problem}_solution/${participant}.${codeLanguage}`);
        // writeStream.write(`${code}`);
        // writeStream.end();

        await fs.writeFile(`submitted_code/problem${process.env.Problem}_solution/${participant}.${codeLanguage}`, code, function (err) {
            if (err) return console.log(err);
            console.log('Hello World > helloworld.txt');
          });
    }
    
    }
    catch(err) {
        console.log(err);
    } finally {
      // await driver.quit();
    }
  };

init();