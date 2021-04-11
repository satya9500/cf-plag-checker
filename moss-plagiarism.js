const { exec } = require('child_process');
require('dotenv').config();
const fs = require('fs');


const langMap = [
    {
        language: 'python',
        extension: 'py'
    },
    {
        language: 'cc',
        extension: 'cpp'
    },
    {
        language: 'javascript',
        extension: 'js'
    },
    {
        language: 'java',
        extension: 'java'
    }
];

let writeStream = fs.createWriteStream("moss_urls.json");


let urlRegex =/(\b(https?|ftp|file):\/\/[-A-Z0-9+&@#\/%?=~_|!:,.;]*[-A-Z0-9+&@#\/%=~_|])/ig;

const start = (problem_code) => {
    
    langMap.forEach((element)=>{

        let dirname = `./submitted_code/problem${problem_code}_solution/${element.extension}/`;
        fs.readdir(dirname, function(err, files) {
            if (err) {
               // some sort of error
            } else {
               if (!files.length) {
                   // directory appears to be empty
                   console.log('empty');
               } else {
                exec(`./moss/moss.pl -l ${element.language} ${dirname}*.${element.extension}`, (err, stdout, stderr) => {
                    if (err) {
                      // node couldn't execute the command
                      console.log(err);
                      return;
                    }
                    // the *entire* stdout and stderr (buffered)
                    //console.log(stdout);
                    stdout.toString().replace(urlRegex, function(url) {
                        console.log(url);
                        writeStream.write(`${url}\n`);
                    });
                  });
               }
            }
        });

        
    })
}

for(let i=0;i<process.env.Problem;i++) {
    start(String.fromCharCode('A'.charCodeAt() + i));
}