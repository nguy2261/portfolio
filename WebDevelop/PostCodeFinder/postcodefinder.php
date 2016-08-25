<?php

?>

<html>
<head>
    <title>Post Code Finder</title>

    <meta charset="utf-8" />
    <meta http-equiv="Content-type" content="text/html; charset=utf-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1" />
    <!-- Latest compiled and minified CSS -->
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css" integrity="sha384-BVYiiSIFeK1dGmJRAkycuHAHRg32OmUcww7on3RYdg4Va+PmSTsz/K68vbdEjh4u" crossorigin="anonymous">

    <!-- Optional theme -->
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap-theme.min.css" integrity="sha384-rHyoN1iRsVXV4nD0JutlnGaslCJuC7uwjduW9SVrLvRYooPp2bWYgmgJQIXwl/Sp" crossorigin="anonymous">

    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.1.0/jquery.min.js"></script>

    <!-- Latest compiled and minified JavaScript -->
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js" integrity="sha384-Tc5IQib027qvyjSMfHjOMaLkfuWVxZxUPnCJA7l2mCWNIpG9mGCD8wGNIcPD7Txa" crossorigin="anonymous"></script>


    <style>
        html, body {
            height: 100%;
            font-family: Baskerville;
        }

        .container {
            background-image: url("backgroundPostCode.jpg");
            width: 100%;
            height: 100%;
            background-size: cover;
            background-position: center;
            padding-top: 80px;
        }

        .center {
            text-align: center;
        }

        .white {
            color: white;
        }

        p {
            padding: 10px 0 20px 0;
        }

        button {
            margin: 20px auto;
        }

        .alert {
            margin: 20px;
            text-align: center;
            display: none;
        }

        #success {
            font-size: 20px;
        }

        #map {
            background-color: white;
        }

        h1 {
            font-family: Bebas Neue;
        }
    </style>


    </head>

<body>

    <div class = "container">
        <div class ="row">
            <div class ="col-md-6 col-md-offset-3 center">
                <h1 class = "center white " > Post Code Finder</h1>
                <p class = "lead center white">Enter the address that you want to find the post code. </p>
                <form class = "form-group">
                    <div class ="form-group">
                        <input type = "text" class = "form-control" name = "city" id = "city" placeholder = "247 Riverside Road Westbury, NY 11590">
                    </div>
                    <button class = "btn btn-success btn-lg" name = "submit" id = "submitAddress">Find the Post Code</button>
                </form>
                
                <div class = "alert alert-success" id = "success"></div>
                <div class = "alert alert-danger" id = "failed">Could not find the zip code</div>

            </div>
        </div>

    </div>

    <script>
        $("#submitAddress").click(function(event){
            var result = "";
            var latt = 0.0;
            var long = 0.0;
            event.preventDefault();
            if ($("#city").val() != ""){
                var address = encodeURIComponent($("#city").val());
                $.ajax({
                    type: "GET",
                    url: "https://maps.googleapis.com/maps/api/geocode/xml?address=" + address + "&key=AIzaSyAZCgWYmhg4JlZQqLLusJCsCo2ZfPmydbg",
                    dataType: "xml",
                    success: processXML
                });

                function processXML(xml){
                    $(xml).find("address_component").each(function() {
                        if ($(this).find("type").text() == "postal_code"){
                            result = "The Zip code of the address is " + $(this).find("long_name").text();
                        }
                    });

                    latt = $(xml).find("geometry").find("location").find("lat").text()
                    long = $(xml).find("geometry").find("location").find("lng").text()
                 

                    if (result != ""){
                        $("#failed").hide();
                        $("#success").html(result).fadeIn();
                    } else {
                        $("#failed").fadeIn();
                        $("#success").hide();
                    }
                }
            } else {
                $("#failed").fadeIn();
                $("#success").hide();
            }
        });

    </script>



</body>
</html>