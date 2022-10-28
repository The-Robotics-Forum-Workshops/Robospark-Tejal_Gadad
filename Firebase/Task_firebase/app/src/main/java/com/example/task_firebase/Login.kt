package com.example.task_firebase

import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.View
import android.widget.Button
import android.widget.EditText
import android.widget.Toast
import com.google.firebase.auth.FirebaseAuth

class Login : AppCompatActivity() {
    lateinit var auth: FirebaseAuth
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_login)
        auth = FirebaseAuth.getInstance()
    }

    fun loginUser(view: View) {
        val btLoginSubmit = findViewById<Button>(R.id.btLoginSubmit)
        val etLoginEmail = findViewById<EditText>(R.id.etLoginEmail)
        val etLoginPwd = findViewById<EditText>(R.id.etLoginPwd)

        val loginEmail : String = etLoginEmail.text.toString()
        val loginPwd : String = etLoginPwd.text.toString()

        btLoginSubmit.setOnClickListener {
            auth.signInWithEmailAndPassword(loginEmail, loginPwd)
                .addOnCompleteListener { task ->
                    if (task.isSuccessful) {
                        Toast.makeText(this, "Login successful", Toast.LENGTH_SHORT).show()
                        startActivity(Intent(this, Welcome::class.java))
                    } else {
                        Toast.makeText(this, "Unable to login. Check your input or try again later", Toast.LENGTH_SHORT).show()
                    }
                }
        }
    }

}