function info_id(id){
    // get data by id
    var data = document.getElementById(id).value;
    console.log(data);
    return data;
}

function get_size(name){
    var sizes = document.getElementsByName(name);
    for(var i=0; i<sizes.length; i++){
        if(sizes[i].checked){
            return sizes[i].value;
        }
    }
}

function get_toppings(name){
    var toppings = document.getElementsByName(name);
    var checked_toppings = '';
    for(var i=0; i<toppings.length; i++){
        if(toppings[i].checked){
            checked_toppings = checked_toppings + ", " + toppings[i].value;
        }
    }
    checked_toppings = checked_toppings.substring(2);
    console.log(checked_toppings);
    return checked_toppings;
}

function showdata(){
    var flavor = info_id("flavor");
    var size = get_size("size");
    var toppings = get_toppings("toppings");
    var cname = info_id("cname");
    var cnum = info_id("cnum");
    var cmail = info_id("cmail");
    var delidate = info_id("delidate");
    var delitime = info_id("delitime");
    var address = info_id("address");

    window.alert("Pizza Flavor: "+flavor
                +"\nSize: "+size
                +"\nToppings: "+toppings
                +"\nCustomer Name: "+cname
                +"\nCustomer Number: "+cnum
                +"\nEmail Address: "+cmail
                +"\nDelivery Date: "+delidate
                +"\nDelivery Time: "+delitime
                +"\nDelivery Address: "+address);
}

function checkdata(){
    var cnum = info_id("cnum");
    var delidate = new Date(info_id("delidate"));
    var delitime = info_id("delitime");
    var hh = delitime.split(":")[0];
    var mm = delitime.split(":")[1];
    var today = new Date();

    if(cnum.length==0 || delidate.length==0 || delitime.length==0){
        window.alert("Inputs are not complete!");
    }
    else if(cnum.length!=11 && cnum.length!=0){
        window.alert("Invalid mobile number format.\nPlease follow the format: 0xxx xxxx xxx");
    }
    else if(today.getFullYear()>delidate.getFullYear()){
        window.alert("Invalid Year! Date already occured.");
    }
    else if(today.getMonth()>delidate.getMonth()){
        window.alert("Invalid Month! Month already occured.");
    }
    else if(today.getDate()>delidate.getDate()){
        window.alert("Invalid Day! Date already occured.");
    }
    else if(hh>0 && hh<6){
        window.alert("Time outside of delivery time.");
    }
    else{
        window.alert("Inputs are complete!");
    }

    if(today.getDate()==delidate.getDate()){
        if(hh<today.getHours()){
            window.alert("Time already occured.");
        }
        else if(hh<=today.getHours() && mm<today.getMinutes()){
        window.alert("Time already occured.");
        }
        else{
            window.alert("Inputs are complete!");
        }
    }
}
