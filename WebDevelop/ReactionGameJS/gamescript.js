     function getRandomColor() {
            var letters = '0123456789ABCDEF';
            var color = '#';
            for (var i = 0; i < 6; i++ ) {
                color += letters[Math.floor(Math.random() * 16)];
            }
        return color;
        }

        var clickedTime; var createdTime; var reactionTime;

        function makeBox(){
            var time = Math.random()*3000;
            var obj = document.getElementById("box");

            if (Math.random() > 0.5){
                obj.style.borderRadius = "50px";
            } else {
                obj.style.borderRadius = "0";
            }

            var top = Math.random()*500;
            var left = Math.random()*1400;
            obj.style.top = top +"px";
            obj.style.left = left+"px";
            setTimeout(function(){
                obj.style.display = "block";
                obj.style.backgroundColor = getRandomColor();
                createdTime = Date.now();
            }, time);
        }

        document.getElementById("box").onclick = function (){
            clickedTime = Date.now();
            reactionTime = (clickedTime - createdTime)/1000;
            document.getElementById("Time").innerHTML = reactionTime;
            this.style.display = "none";
            makeBox();
        }

        makeBox();