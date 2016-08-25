<?php
    include("login.php");
    // Report all errors except E_NOTICE   
    error_reporting(E_ALL ^ E_NOTICE);
?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->
    <title>Secret Diary</title>

    <!-- Bootstrap -->
    <link href="css/bootstrap.min.css" rel="stylesheet">

    <!-- HTML5 shim and Respond.js for IE8 support of HTML5 elements and media queries -->
    <!-- WARNING: Respond.js doesn't work if you view the page via file:// -->
    <!--[if lt IE 9]>
      <script src="https://oss.maxcdn.com/html5shiv/3.7.3/html5shiv.min.js"></script>
      <script src="https://oss.maxcdn.com/respond/1.4.2/respond.min.js"></script>
    <![endif]-->

    <style>
        .navbar-brand {
            font-size: 1.8em;
        }
        
        #topContainer {
            background-image: url("background.jpg");
            background-size: cover;
        }
        
        #topRow {
            margin-top: 100px;
            text-align: center;
        }
        
        #topRow h1 {
            font-size: 200%;
            font-family: baskerville;
        }
        
        .marginTop {
            margin-top: 30px;
        }
        
        .center {
            text-align: center;
        }
        
        .title {
            margin-top: 100px;
            font-size: 300%;
            font-family baskerville;
        }

        #footer {
            background-color: #B0D1FB;
        }

        .glyphicon-download {
            font-size: 6em;
        }

        .storeImage {
            width: 250px;
        }
    </style>

</head>

<body data-spy = "scroll" data-target =".navbar-collapse">
    <!-- jQuery (necessary for Bootstrap's JavaScript plugins) -->
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/1.12.4/jquery.min.js"></script>
    <!-- Include all compiled plugins (below), or include individual files as needed -->
    <script src="js/bootstrap.min.js"></script>

    <div class="navbar navbar-default navbar-fixed-top">
        <div class="container">
            <div class="navbar-header">

                <button class="navbar-toggle" data-toggle="collapse" data-target=".navbar-collapse">
                    <span class = "icon-bar"></span>
                    <span class = "icon-bar"></span>
                    <span class = "icon-bar"></span>
                </button>

                <a class="navbar-brand">Secret Diary</a>
            </div>

            <div class="collapse navbar-collapse">
                <form class="navbar-form navbar-right" method = "post">
                    <div class="form-group">
                        <input type="email" name = "login_email" placeholder="Email" class="form-control" />
                    </div>
                    <div class="form-group">
                        <input type="password" name = "login_password" placeholder="Password" class="form-control" />
                    </div>
                    <input type="submit" name = "submit" class="btn btn-success" value = "Log In"></input>
                </form>
            </div>
        </div>
    </div>

    <div class="container contentContainer" id="topContainer">
        <div id = "home"></div>
        <div class="row">
            <div class="col-md-6 col-md-offset-3" id="topRow">
                <h1>Your Own Secret Diary</h1>
                <p class="lead center">Your own secret diary with you and wherever you go</p>
                
                <?php
                    if ($error) {
                        echo '<div class = "alert alert-danger">'.$error.'</div>';
                    }

                    if ($message) {
                        echo '<div class = "alert alert-success">'.$message.'</div>';
                    }

                ?>
                
                
                
                
                <p class="bold">Interested? Sign up here</p>

                <form method = "post">
                    <div class="form-group">
                        <label for = "email">Email Address </label>
                        <input type="email" name = "email" class="form-control" placeholder="Your email" />
                    </div>

                    <div class="form-group">
                        <label for = "password">Your password</label>
                        <input type="password" name = "password" class="form-control" placeholder="Your password" />
                    </div>

                    <input type="submit" class="btn btn-success btn-lg marginTop" name = "submit" value = "Sign Up"/>
                </form>

            </div>
        </div>
    </div>

    <script>
        $(".contentContainer").css("min-height",$(window).height());
    </script>


</body>

</html>





