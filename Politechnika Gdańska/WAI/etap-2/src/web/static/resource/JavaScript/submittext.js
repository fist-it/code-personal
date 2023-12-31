document.addEventListener("DOMContentLoaded", function () {
  var bugForm = document.getElementById("bugForm");
  var confirmationMessage = document.getElementById("confirmationMessage");
  var submitted = sessionStorage.getItem("bugdesc");
  if (submitted) {
    bugForm.style.display = "none";
    confirmationMessage.style.display = "block";
    var confirmationMessage = document.createElement("p");
    confirmationMessage.appendChild(
      document.createTextNode("Dziękuję za zgłoszenie błędu: " + sessionStorage.getItem("bugdesc"))
    );
    var confirmationContainer = document.getElementById(
      "confirmationContainer"
    );
    confirmationContainer.appendChild(confirmationMessage);
    confirmationContainer.style.display = "block";
  } else {
    bugForm.addEventListener("submit", e);
  }
});

function e(event) {
  var bugDescription = document.getElementById("txtbug").value;
  sessionStorage.setItem("bugdesc", bugDescription);
  var confirmationMessage = document.createElement("p");
  confirmationMessage.appendChild(
    document.createTextNode("Dziękuję za zgłoszenie błędu: " + bugDescription)
  );
  var confirmationContainer = document.getElementById("confirmationContainer");
  confirmationContainer.appendChild(confirmationMessage);
  confirmationContainer.style.display = "block";
  bugForm.style.display = "none";
}
