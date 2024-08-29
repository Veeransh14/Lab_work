#!/bin/bash

# Function to execute different loops
function loops_example() {
    echo "For loop example: "
    for i in {1..5}
    do
        echo "Iteration: $i"
    done

    echo -e "\nWhile loop example: "
    count=1
    while [ $count -le 5 ]
    do
        echo "Iteration: $count"
        count=$((count + 1))
    done
}

# Function to perform arithmetic operations
function arithmetic_operations() {
    echo -e "\nEnter two numbers:"
    read -p "First number: " num1
    read -p "Second number: " num2

    sum=$((num1 + num2))
    difference=$((num1 - num2))
    product=$((num1 * num2))
    quotient=$((num1 / num2))

    echo -e "\nResults:"
    echo "Sum: $sum"
    echo "Difference: $difference"
    echo "Product: $product"
    echo "Quotient: $quotient"
}

# Function to execute conditional statements
function conditional_statements() {
    read -p "Enter a number: " number

    if [ $number -gt 0 ]; then
        echo "$number is positive."
    elif [ $number -lt 0 ]; then
        echo "$number is negative."
    else
        echo "$number is zero."
    fi
}

# Function to create a text file (.txt) with personal data
function create_resume() {
    read -p "Enter your full name: " name
    read -p "Enter your email: " email
    read -p "Enter your phone number: " phone
    read -p "Enter your academic qualification: " qualification
    read -p "Enter your skills (comma-separated): " skills

    filename="${name// /_}_Resume.txt"
    echo -e "\nCreating resume file: $filename"

    cat <<EOF > $filename
Personal Information
--------------------
Name: $name
Email: $email
Phone: $phone

Academic Details
----------------
Qualification: $qualification

Skills
------
$skills
EOF

    echo -e "\nResume created successfully!"
}

# Main script execution
echo "Choose an option:"
echo "1. Execute loops"
echo "2. Execute arithmetic operations"
echo "3. Execute conditional statements"
echo "4. Create a resume text file"
read -p "Enter your choice (1-4): " choice

case $choice in
    1) loops_example ;;
    2) arithmetic_operations ;;
    3) conditional_statements ;;
    4) create_resume ;;
    *) echo "Invalid choice!" ;;
esac
