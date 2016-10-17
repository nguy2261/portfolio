var Fetch = require('whatwg-fetch');
var rootURL = 'https://api.imgur.com/3/';
var apiKey = '223651bfe6a6a9f';

module.exports = {
  get: function(url){
    return fetch(rootURL + url, {
      headers: {
        'Authorization': 'Client-ID ' + apiKey
      }
    })
    .then(function(response){
      return response.json();
    })
  }
};
