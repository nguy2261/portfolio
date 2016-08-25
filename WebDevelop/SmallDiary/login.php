<?php
    // Report all errors except E_NOTICE   
    error_reporting(E_ALL ^ E_NOTICE);
    
    session_start();

    //Logout
    if ($_GET["logout"] == 1 AND $_SESSION['id']){
        session_destroy();
        $message = "You have been logged out. Have a nice day";
        session_start();
    }


    include("connection.php");
    $error = "";
    if ($_POST['submit'] == 'Sign Up') 
    {
        if (!$_POST['email'])
            $error = "Please enter your email <br />";
        else 
            if (!filter_var($_POST['email'],FILTER_VALIDATE_EMAIL))
                $error = "Please enter correct email <br />";
            if (!$_POST['password'])
                $error .= "Please enter your password <br />";
            else {
                if (strlen($_POST['password']) < 8)
                    $error .= "Please enter a password longer than 8 characters <br />";
                if (!preg_match('`[A-Z]`',$_POST['password']))
                    $error .= 'Please include at least one capital letter in your password <br />';            
            }       

        if ($error) 
            $error ="There were error(s) in your signup details <br />".$error;
        else 
        {   
            $link = mysqli_connect("79.170.44.102","cl24-nguy2261","sK9z-ej!E","cl24-nguy2261");
            $query = "SELECT * FROM users WHERE email = '".mysqli_real_escape_string($link,$_POST['email'])."'";
            $result = mysqli_query($link,$query);
            $result = mysqli_num_rows($result);
            if ($result){
                $error = "That email address is already registered.";
            } else {
                $query = "INSERT INTO `users` (`email`,`password`) VALUES('".mysqli_real_escape_string($link,$_POST['email'])."', '".md5(md5($_POST['email']).$_POST['password'])."')";
                mysqli_query ($link,$query);
                echo "You've just signup";
                $_SESSION['id'] = mysqli_insert_id($link);
                print_r($_SESSION);
                header("Location:mainpage.php");
            }
        }
    }


    if ($_POST['submit'] == "Log In"){
        $link = mysqli_connect("79.170.44.102","cl24-nguy2261","sK9z-ej!E","cl24-nguy2261");
        $query = "SELECT * FROM users WHERE email = '".mysqli_real_escape_string($link,$_POST['login_email'])."' AND password = '".md5(md5($_POST['login_email']).$_POST['login_password'])."' LIMIT 1";
        $result = mysqli_query($link,$query);
        $row = mysqli_fetch_array($result);
        if ($row) {
            $_SESSION['id'] = $row['id'];
            header("Location:mainpage.php");

        } else {
            $error = "We couldn not find user with that email and password. Please try again";
        }
    }
?>