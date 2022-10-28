package com.example.task_firebase

import android.content.ContentValues.TAG
import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import android.view.View
import android.widget.*
import com.google.firebase.auth.FirebaseAuth
import com.google.firebase.firestore.FirebaseFirestore

class SignUp : AppCompatActivity() {
    private lateinit var auth: FirebaseAuth
    private var db: FirebaseFirestore? = null
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_sign_up)
        auth = FirebaseAuth.getInstance()
        db = FirebaseFirestore.getInstance()
    }

    fun registerUser(view: View) {

        val etName = findViewById<EditText>(R.id.etName)
        val etAge = findViewById<EditText>(R.id.etAge)
        val etMobile = findViewById<EditText>(R.id.etMobile)
        val etEmail = findViewById<EditText>(R.id.etEmail)
        val etPwd = findViewById<EditText>(R.id.etPwd)
        val etConPwd = findViewById<EditText>(R.id.etConPwd)
        val btSubmit = findViewById<Button>(R.id.btSubmit)

        val name : String = etName.text.toString()
        val age : String = etAge.text.toString()
        val mobile : String = etMobile.text.toString()
        val pwd : String = etPwd.text.toString()
        val conpwd : String = etConPwd.text.toString()
        val email : String = etEmail.text.toString()

        val user = hashMapOf<String, Any>(
            "name" to name,
            "age" to age,
            "mobile" to mobile,
            "email" to email,
            "pwd" to pwd
        )

        db?.collection("Users")?.document(email)
            ?.set(user)
            ?.addOnSuccessListener { Log.d(TAG, "DocumentSnapshot successfully written!") }
            ?.addOnFailureListener { e -> Log.w(TAG, "Error writing document", e) }

        btSubmit.setOnClickListener {
            if (pwd.equals(conpwd)) {
                auth.createUserWithEmailAndPassword(email, pwd)
                    .addOnCompleteListener { task ->
                        if (task.isSuccessful) {
                            Toast.makeText(this, "Registration Successful", Toast.LENGTH_SHORT).show()
                            startActivity(Intent(this, Home::class.java))
                        }
                        else {
                            Toast.makeText(this, "An error occurred", Toast.LENGTH_SHORT).show()
                        }
                    }
            }
            else {
                Toast.makeText(this, "Passwords do not match", Toast.LENGTH_SHORT).show()
            }
        }
    }
}