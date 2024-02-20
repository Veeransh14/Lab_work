function processPayment() {
    // Simulate payment processing
    var name = document.getElementById('name').value;
    var email = document.getElementById('email').value;
    var address = document.getElementById('address').value;
    var paymentMethod = document.getElementById('paymentMethod').value;
    var cardType = document.getElementById('cardType').value;
    var cardNumber = document.getElementById('cardNumber').value;
    var expiry = document.getElementById('expiry').value;
    var cvv = document.getElementById('cvv').value;
    var amount = document.getElementById('amount').value;

    // You can replace this with actual payment processing code
    // This is just a demonstration
    // Here, we're simply showing a success message
    var paymentStatus = document.getElementById('paymentStatus');
    paymentStatus.innerHTML = `Payment successful! Amount paid: $${amount}`;

    // Prevent form submission
    return false;
}
