<?php
// Define a set of random titles, content, and colors
$titles = ["Welcome to My Website", "Random Page", "Explore the Unknown", "PHP Magic"];
$contents = [
    "This is a random website created using PHP.",
    "Here, you can explore dynamically generated content.",
    "PHP allows you to create websites with ease!",
    "Every time you reload, this website changes!"
];
$bgColors = ["#ffcccc", "#ccffcc", "#ccccff", "#ffffcc", "#ccffff", "#ffccff"];

// Pick a random title, content, and background color
$randomTitle = $titles[array_rand($titles)];
$randomContent = $contents[array_rand($contents)];
$randomBgColor = $bgColors[array_rand($bgColors)];
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title><?php echo $randomTitle; ?></title>
    <style>
        body {
            background-color: <?php echo $randomBgColor; ?>;
            font-family: Arial, sans-serif;
            color: #333;
            text-align: center;
            padding: 50px;
        }
        h1 {
            font-size: 3em;
        }
        p {
            font-size: 1.5em;
        }
    </style>
</head>
<body>
    <h1><?php echo $randomTitle; ?></h1>
    <p><?php echo $randomContent; ?></p>
    <button onclick="location.reload()">Generate New Content</button>
</body>
</html>
