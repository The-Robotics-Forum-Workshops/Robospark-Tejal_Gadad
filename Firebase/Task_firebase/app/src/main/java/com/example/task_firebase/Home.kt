package com.example.task_firebase

import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.View

class Home : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_home)
    }

    fun gotoSignUp(view: View){
        startActivity(Intent(this,SignUp:: class.java))
    }

    fun gotoLogin(view: View){
        startActivity(Intent(this,Login:: class.java))
    }

}
