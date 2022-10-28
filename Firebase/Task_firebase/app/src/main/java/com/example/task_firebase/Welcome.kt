package com.example.task_firebase

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.TextView

class Welcome : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_welcome)

        val DisplayName = findViewById<TextView>(R.id.tvDisplayName)
        val DisplayAge = findViewById<TextView>(R.id.tvDisplayAge)
        val DisplayMobile = findViewById<TextView>(R.id.tvDisplayMobile)
        val DisplayGender = findViewById<TextView>(R.id.tvDisplayGender)
        val DisplayBloodGrp = findViewById<TextView>(R.id.tvDisplayBloodGrp)

    }
}