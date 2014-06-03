// Function to send a message to the Pebble using AppMessage API

var Id;
var amt;

function sendBalance(msg) {
	Pebble.sendAppMessage({"balance": msg});
}

function sendContact(msg) {
  
	Pebble.sendAppMessage({"contact": msg});
  console.log("contact1 sent");
  }


function sendFeed(msg) {
	Pebble.sendAppMessage({"feedd": msg});
  }






function getContacts() {
  console.log("Getting Contacts");
  
  var baseUrlBal = "https://uat.dwolla.com/oauth/rest/contacts/?oauth_token=n16XCg1VC%2BnCK5WNa%2BozxzLRBHrQIR55i8uRcBm0o5%2FGKRy%2Fy0";
  var urlBal = baseUrlBal;
  console.log("URL: " + urlBal);

  var req = new XMLHttpRequest();
  req.open('GET', urlBal, true);
  req.onload = function(e) {
    if (req.readyState == 4 && req.status == 200) {
      var response = JSON.parse(req.responseText);
  
      var Contacts = response.Response;
      var str="";
      
          for (var i = 0; i < Contacts.length; i++) {
       console.log("ContactName " + Contacts[i].Name);
             str=str+"|"+Contacts[i].Name;
      }
      
    sendContact(str);
  }
    
    
    
    else {
      console.log("Error Getting Contact: " + req.status);
      sendContact("999");
    }
  };
  req.send(null);
}


function postPay()
{
  
  console.log("Paying post");
  
  var baseUrl="https://uat.dwolla.com/oauth/rest/transactions/send";
  
  var req = new XMLHttpRequest();   // new HttpRequest instance 
req.open('POST', baseUrl);
req.setRequestHeader("Content-Type", "application/json");
req.send(JSON.stringify({
  oauth_token: "n16XCg1VC%2BnCK5WNa%2BozxzLRBHrQIR55i8uRcBm0o5%2FGKRy%2Fy0",
    pin: "1234",
    destinationId: Id,
    amount: amt,
    destinationType: "Dwolla",
    assumeCosts: "false",
    additionalFees: [],
    assumeAdditionalFees: "false"

  }));
}

                     
function postRequest()
{
  
  console.log("Paying post");
  
  var baseUrl="https://uat.dwolla.com/oauth/rest/requests/";
  
  var req = new XMLHttpRequest();   // new HttpRequest instance 
req.open('POST', baseUrl);
req.setRequestHeader("Content-Type", "application/json");
req.send(JSON.stringify({
  oauth_token: "n16XCg1VC%2BnCK5WNa%2BozxzLRBHrQIR55i8uRcBm0o5%2FGKRy%2Fy0",
    sourceId: Id,
    amount: amt

  }));
}
 
                     
                     
                     
                     
                     
                     
                     
function getFeed() {
  console.log("Getting Feed");
  
  var baseUrlBal = "https://uat.dwolla.com/oauth/rest/transactions/?oauth_token=n16XCg1VC%2BnCK5WNa%2BozxzLRBHrQIR55i8uRcBm0o5%2FGKRy%2Fy0";
  var urlBal = baseUrlBal;
  console.log("URL: " + urlBal);

  var req = new XMLHttpRequest();
  req.open('GET', urlBal, true);
  req.onload = function(e) {
    if (req.readyState == 4 && req.status == 200) {
      var response = JSON.parse(req.responseText);
      
      var str="";
      var Feed = response.Response;
      for (var i = 0; i < Feed.length; i++) {
       console.log("Name " + Feed[i].DestinationName+ Feed[i].Amount);
        str+="|"+Feed[i].DestinationName+" $"+ Feed[i].Amount;
        
  
    }
      
      sendFeed(str);
  }
    else {
      console.log("Error Getting Contact: " + req.status);
      sendFeed("99");
    }
  };
  req.send(null);
}








function getBalance() {
  console.log("Getting Balance");
  
  var baseUrlBal = "https://uat.dwolla.com/oauth/rest/balance/?oauth_token=n16XCg1VC%2BnCK5WNa%2BozxzLRBHrQIR55i8uRcBm0o5%2FGKRy%2Fy0";
  var urlBal = baseUrlBal;
  console.log("URL: " + urlBal);

  var req = new XMLHttpRequest();
  req.open('GET', urlBal, true);
  req.onload = function(e) {
    if (req.readyState == 4 && req.status == 200) {
      var response = JSON.parse(req.responseText);
      var Balance = response.Response;
      var DollarBalance = "$" + Balance.toFixed(0);

      console.log("Balance: " + DollarBalance);
      sendBalance(DollarBalance);
      console.log("Balance Mess Send");
    }
    else {
      console.log("Error Getting Balance: " + req.status);
      sendBalance("999");
    }
  };
  req.send(null);
}

// Called when JS is ready
Pebble.addEventListener("ready",
  function(e) {
    getBalance();
    getContacts();
    getFeed();
   
  });


Pebble.addEventListener("appmessage",
  function(e) {
    console.log("Received message: " + e.payload);
    
  }
);


