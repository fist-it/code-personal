document.addEventListener("DOMContentLoaded", function () {
  var bugForm = document.getElementById("bugForm");
  var confirmationMessage = document.getElementById("confirmationMessage");
  var submitted = sessionStorage.getItem("bugdesc");
  if (submitted) {
    bugForm.style.display = "none";
    confirmationMessage.style.display = "block";
    confirmationMessage.innerHTML =
      "Dziękuję za zgłoszenie błędu: " + submitted;
  } else {
    bugForm.addEventListener("submit", e);
  }
});

function e(event) {
  var bugDescription = document.getElementById("txtbug").value;
  sessionStorage.setItem("bugdesc", bugDescription);
  confirmationMessage.innerHTML =
    "Dziękuję za zgłoszenie błędu: " + bugDescription;
  confirmationMessage.style.display = "block";
  bugForm.style.display = "none";
}
