<?php

?>

<html>
<head>
    <title>Weather Scraper</title>

    <meta charset="utf-8" />
    <meta http-equiv="Content-type" content="text/html; charset=utf-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1" />
    <!-- Latest compiled and minified CSS -->
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css" integrity="sha384-BVYiiSIFeK1dGmJRAkycuHAHRg32OmUcww7on3RYdg4Va+PmSTsz/K68vbdEjh4u" crossorigin="anonymous">

    <!-- Optional theme -->
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap-theme.min.css" integrity="sha384-rHyoN1iRsVXV4nD0JutlnGaslCJuC7uwjduW9SVrLvRYooPp2bWYgmgJQIXwl/Sp" crossorigin="anonymous">

    <!-- Latest compiled and minified JavaScript -->
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js" integrity="sha384-Tc5IQib027qvyjSMfHjOMaLkfuWVxZxUPnCJA7l2mCWNIpG9mGCD8wGNIcPD7Txa" crossorigin="anonymous"></script>

    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.1.0/jquery.min.js"></script>

    <style>
        html, body {
            height: 100%;
            font-family: baskerville;
        }

        .container {
            background-image: url("weatherback.jpg");
            width: 100%;
            height: 100%;
            background-size: cover;
            background-position: center;
            padding-top: 150px;
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
    </style>


    </head>

<body>

    <div class = "container">
        <div class ="row">
            <div class ="col-md-6 col-md-offset-3 center">
                <h1 class = "center white "> Weather Forecaster </h1>
                <p class = "lead center white">Enter your city below to get your forecast. </p>
                <form class = "form-group">
                    <div class ="form-group">
                        <input type = "text" class = "form-control" name = "city" id = "city" placeholder = "New York, Paris, Seattle, etc..">
                    </div>
                    <button class = "btn btn-success btn-lg" name = "submit" id = "submitWeather">Find the Weather</button>
                </form>
                
                <div class = "alert alert-success" id = "success"></div>
                <div class = "alert alert-danger" id = "failed">Could not find data or city name</div>

            </div>
        </div>

    </div>

    <script>
        $("#submitWeather").click(function(event){
            event.preventDefault();
            if ($("#city").val() == ""){
                $("#failed").fadeIn();
            } else {
                $.get("scraper.php?city="+$("#city").val(),function (data){
                    if (data == ""){
                        $("#success").hide();
                        $("#failed").fadeIn();
                    } else {
                        $("#failed").hide();
                        $("#success").html(data).fadeIn();
                    }
                });
            }
            });

    </script>



</body>
</html>