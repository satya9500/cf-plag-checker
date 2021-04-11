require('dotenv').config();
const fs = require('fs');
const dir ='./submitted_code';
const problems = process.env.Problem;

const fresh = () => {
    if (!fs.existsSync(dir)){
        fs.mkdirSync('./submitted_code');
    
        for(let i=0;i<problems;i++) {
            const code = String.fromCharCode('A'.charCodeAt() + i);
            fs.mkdirSync(`./submitted_code/problem${code}_solution`);
            fs.mkdirSync(`./submitted_code/problem${code}_solution/java`);
            fs.mkdirSync(`./submitted_code/problem${code}_solution/cpp`);
            fs.mkdirSync(`./submitted_code/problem${code}_solution/py`);
            fs.mkdirSync(`./submitted_code/problem${code}_solution/js`);
        }
    }
}

module.exports = fresh;