var b = require('bonescript');
var voltage = 0;
b.pinMode('P9_20',b.OUTPUT);
// b.pinMode('P9_33')
setInterval(read , 100);

function read(){
    b.analogRead('P9_33',print);
}

function print(x){
    var distance_in_inch;
    voltage = x.value*1.8;
    distance_in_inch = voltage/.00699 ;
    console.log('x.value = ' + voltage);

    distance_in_inch = voltage/.00699 ;
    // console.log('x.value = ' + voltage);
    // console.log('You can say it to ' + parseFloat(distance_in_inch).tofixed(2) + ' inch away');
    if(distance_in_inch < 0.1){
        console.log('STOP! , There is a object' + parseFloat(distance_in_inch).tofixed(2) + ' inch away');
        b.digitalWrite('P9_20',b.HIGH);
    }    
      else
        b.digitalWrite('P9_20',b.LOW);

}