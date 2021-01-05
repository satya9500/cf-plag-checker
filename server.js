const {Builder, By, Key, until} = require('selenium-webdriver');
require('dotenv').config();
const fs = require('fs');
let participants = fs.readFileSync('participants.json');
participants = JSON.parse(participants).username;
const fresh = require('./fresh');
fresh();

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
        extension: 'cpp'
    },
    {
        name: 'GNU C++17',
        extension: 'cpp'
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

const init = async function example(problem_code) {
    let driver = await new Builder().forBrowser('firefox').build();
    try {
    
    const submissionUrl = [];

    for(participant of participants) {
        try{
            await driver.get(`https://codeforces.com/contest/${process.env.ContestCode}/status/${problem_code}`);
            await (await driver.findElement(By.name("participantSubstring"))).clear();
            await driver.findElement(By.name("participantSubstring")).sendKeys(participant, Key.RETURN);
            const url = await driver.findElement(By.className(`view-source`)).getAttribute('href');
            driver.get(url);
            submissionUrl.push(url);
            const code = await (await driver.findElement(By.className('prettyprint'))).getText();
            console.log(code);
            let codeLanguage = await (await driver.findElement(By.xpath('//*[@id="pageContent"]/div[2]/div[6]/table/tbody/tr[2]/td[4]'))).getText();
            codeLanguage = findExtension(codeLanguage);
            const username = await(await driver.findElement(By.className('rated-user'))).getText();
            
            fs.writeFile(`submitted_code/problem${problem_code}_solution/${codeLanguage}/${username}.${codeLanguage}`, code, function (err) {
                if (err) return console.log(err);
                console.log(`${username}.${codeLanguage}`);
              });
        } catch(err) {
            console.log(err);
        }
    }
    
    }
    catch(err) {
        console.log(err);
    } finally {
      await driver.quit();
    }
  };

for(let i=0;i<process.env.Problem;i++) {
    init(String.fromCharCode('A'.charCodeAt() + i));
}
