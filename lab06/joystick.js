var b = require('bonescript');
var pos = {};
var q,w;
var led1 = 'P9_14';
var led2 = 'P9_16';
var led3 = 'P8_13';
var led4 = 'P8_19';

b.pinMode(led1 , b.OUTPUT);
b.pinMode(led2 , b.OUTPUT);

b.pinMode(led3 , b.OUTPUT);
b.pinMode(led4 , b.OUTPUT);


setInterval(read , 1);
function read(){
    b.analogRead('P9_36', onX);
}

function onX(x) {
    pos.x = parseFloat(x.value * 100).toFixed(2);//conveerts string to float
   q = pos.x;
    b.analogRead('P9_38', onY);
}

function onY(x) {
	pos.y = parseFloat(x.value * 100).toFixed(2);
	w = pos.y;
	console.log(JSON.stringify(pos));
	check();
}

function check (){
    if(q <= 10){
        b.digitalWrite(led1 , b.HIGH);
        b.digitalWrite(led2 , b.LOW);
        b.digitalWrite(led3 , b.LOW);
        b.digitalWrite(led4 , b.LOW);
    }
    else if(w <= 10){
        b.digitalWrite(led1 , b.LOW);
        b.digitalWrite(led2 , b.HIGH);
        b.digitalWrite(led3 , b.LOW);
        b.digitalWrite(led4 , b.LOW);
    }
    else if(q >= 90){
        b.digitalWrite(led1 , b.LOW);
        b.digitalWrite(led2 , b.LOW);
        b.digitalWrite(led3 , b.HIGH);
        b.digitalWrite(led4 , b.LOW);
    }
    else if(w >= 90){
        b.digitalWrite(led1 , b.LOW);
        b.digitalWrite(led2 , b.LOW);
        b.digitalWrite(led3 , b.LOW);
        b.digitalWrite(led4 , b.HIGH);
    }
    else{
       b.digitalWrite(led1 , b.LOW);
        b.digitalWrite(led2 , b.LOW);
        b.digitalWrite(led3 , b.LOW);
        b.digitalWrite(led4 , b.LOW);
    }
}